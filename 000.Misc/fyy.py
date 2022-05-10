import requests
from requests_html import HTMLSession

url = "https://hw101.jilin-ai.com:19443/problem/10"

# # set UA

UA = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.75 Safari/537.36"

# # send request

# r = requests.get(url, headers={"User-Agent": UA}, verify=False)

# print(r.text)

session = HTMLSession(verify=False)
r = session.get(url, headers={"User-Agent": UA}, verify=False)
# r = requests.get("https://hw101.jilin-ai.com:19443/problem/10")
r.html.render()
