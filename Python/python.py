# -*- coding: utf-8 -*-
# _author_ = 
# Email: 
"""
协议：仅支持 HTTPS 传输
url格式：https://{hostname}:{port}/artemis/{uri}
# AK\SK摘要认证
调用 API 时，如果API需要安全认证，首先需要获取API的授权，得到AppKey和AppSecret；
其次，拼接签名字符串，将计算后的签名放在请求的 Header 传入，网关会通过对称计算签名来验证请求者的身份。
"""
 
import os
import base64
import json
import time
import uuid
import hmac  # hex-based message authentication code 哈希消息认证码
import hashlib  # 提供了很多加密的算法
import requests
 
 
base_url = "https://192.168.15.18:443"  # 可以正常访问的IP地址
# 注意增加/artemis
api_get_address_url = "/artemis/api/v1/oauth/token"
appKey = "27077132"
appSecret = "Rl4NTbqGJw93uDEzkOkL"
http_method = "POST"
 
 
def sign(key, value):
    temp = hmac.new(key.encode(), value.encode(), digestmod=hashlib.sha256)
    return base64.b64encode(temp.digest()).decode()
 
 
x_ca_nonce = str(uuid.uuid4())
x_ca_timestamp = str(int(round(time.time()) * 1000))
# sign_str 的拼接很关键，不然得不到正确的签名
sign_str = "POST\n*/*\napplication/json" + "\nx-ca-key:" + appKey + "\nx-ca-nonce:" + \
           x_ca_nonce + "\nx-ca-timestamp:" + x_ca_timestamp + "\n" + \
           api_get_address_url
print(sign_str)
 
signature = sign(appSecret, sign_str)
print("[INFO] 获取到的签名值为：", signature)
 
headers = {
    "Accept": "*/*",
    "Content-Type": "application/json",
    "x-ca-key": appKey,  # appKey，即 AK
    "x-ca-signature-headers": "x-ca-key,x-ca-nonce,x-ca-timestamp",
    "x-ca-signature": signature,  # 需要计算得到的签名，此处通过后台得到
    "x-ca-timestamp": x_ca_timestamp,  # 时间戳
    "x-ca-nonce": x_ca_nonce  # UUID，结合时间戳防重复
}

headers = {'Accept': '*/*', 'Content-Type': 'application/json', 'x-ca-key': '27077132', 'x-ca-signature-headers': 'x-ca-key,x-ca-nonce,x-ca-timestamp', 'x-ca-signature': 'ofy2vVHVAhZjcrEWmVKmsk/gCrqhr3jYuEyJgBqk6cc=', 'x-ca-timestamp': '1634262323000', 'x-ca-nonce': 'a377e284-7594-4783-844a-e9bdf4a66249'}

print(headers)
 
body = {}

url = base_url + api_get_address_url
results = requests.post(url, data=json.dumps(body), headers=headers,  verify=False)
print("RESULT:",results)
print("RESULT JSON:",results.json())