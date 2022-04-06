# coding='utf-8'
import socket
import time
import ssl

redirect_host = '123.123.123.123'
redirect_port = 80

login_host = 'wifi.scnu.edu.cn'
login_port = 8443

redirect_request_str = 'GET / HTTP/1.1\r\nHost: 123.123.123.123\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2\r\nAccept-Encoding: gzip, deflate\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\n\r\n'

login_str_line = 'POST /eportal/InterFace.do?method=login HTTP/1.1\r\n'

login_str_headers = 'Host: wifi.scnu.edu.cn:8443\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36\r\nAccept: */*\r\nAccept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2\r\nAccept-Encoding: gzip, deflate\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8\r\nContent-Length: duetocontent\r\nOrigin: http://wifi.scnu.edu.cn:8443\r\nConnection: keep-alive\r\n\r\n'

login_str_content_head = 'userId=theuserid&password=thepassword&service=&queryString='
login_str_content_tail = '&operatorPwd=&operatorUserId=&validcode=&passwordEncrypt=true'


def info_request(redirect_host, redirect_port, redirect_request_str):
    # 在重定向处获取queryString
    print('[*]requesting redirection : \r\n')
    flag = 0
    while(1):
        print('[*]trying \r\n')
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((redirect_host, redirect_port))
        s.sendall(redirect_request_str.encode())
        re = s.recv(1024).decode()
        s.close()

        if(re == ''):
            flag = flag+1
            if(flag == 3):
                return 0
            continue
        else:
            querystr = re[(re.find('wlanuserip')):(re.find('\'</script>'))]
            print('[*]requesting success \r\n')

            print(querystr+'\r\n')
            return querystr


def login(login_host, login_port, querystr, id=None, pwd=None):

    if(id == None or pwd == None):
        print('[*]Please check the account.\r\n')
        return 0

    print('[*]trying to login  \r\n')
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((login_host, login_port))
    s = ssl.wrap_socket(s, keyfile=None, certfile=None, server_side=False,
                        cert_reqs=ssl.CERT_NONE, ssl_version=ssl.PROTOCOL_TLSv1_2)

    global login_str_headers
    global login_str_content_head
    login_str_content_head = login_str_content_head.replace(
        'theuserid', id).replace('thepassword', pwd)
    querystr = querystr.replace('=', '%253D')
    querystr = querystr.replace('&', '%2526')
    content = login_str_content_head+querystr+login_str_content_tail
    login_str_headers = login_str_headers.replace(
        'duetocontent', str(len(content)))

    login_str = login_str_line+login_str_headers+content
    print(login_str+'\r\n')
    s.sendall(login_str.encode())
    time.sleep(0.5)
    re = s.recv(1024).decode()
    s.close()
    if("success" in re):
        print('[*]login Successfully \r\n')
        return 1
    else:
        print('[*]login failed \r\n')
        print(re)
        return 0


query = querystr = info_request(
    redirect_host, redirect_port, redirect_request_str)
# 用浏览器 F12 抓信息填下面
print(login(login_host, login_port, query, id='', pwd=''))
