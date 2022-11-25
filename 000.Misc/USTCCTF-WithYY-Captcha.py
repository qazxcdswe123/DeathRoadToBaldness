import requests

r = requests.Session()
url = "http://202.38.93.111:10047/?token=4530%3AMEQCIEnc1XE9rkQeNcstxsDMmgt6hs0LhLz%2F6FY3arEp48BAAiBBcCbNqU8mF0uiyZLrOFYOKK%2FffF8LRTsUss6Dajwi9A%3D%3D"
r.get(url)
x = r.get("http://202.38.93.111:10047/xcaptcha")
k = []

for i in x.text.split("\n"):
    if "的结果是" in i:
        i = i.split(">")[1].split(" ")[0].split("\n")
        for j in i:
            if j != "":
                k.append(eval(j))
            
print(k)
payload = {"captcha1": k[0], "captcha2": k[1], "captcha3": k[2]}
x = r.post("http://202.38.93.111:10047/xcaptcha", data=payload)
print(x.text)