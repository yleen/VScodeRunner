const Crypto = require('crypto-js');
process.env['NODE_TLS_REJECT_UNAUTHORIZED']='0';

base_url = "https://192.168.15.18:443"
api_get_address_url = "/artemis/api/v1/oauth/token"
appKey = "27077132"
appSecret = "Rl4NTbqGJw93uDEzkOkL"
http_method = "POST"
 
 
function sign(appSecret, sign_str){
    sign_secret = Crypto.HmacSHA256(sign_str,appSecret).toString(Crypto.enc.Base64) 
    return sign_secret
}
 
x_ca_nonce = uuid(); 
x_ca_timestamp = Date.parse( new Date());
sign_str = "POST\n" +
            "*/*" + "\n" +
            "application/json\n" + 
            "x-ca-key:" + appKey + "\n" + 
            "x-ca-nonce:" + x_ca_nonce + "\n" +
            "x-ca-timestamp:" + x_ca_timestamp + "\n" +
           api_get_address_url

console.log("sign_str:",sign_str)
 
signature = sign(appSecret, sign_str)
console.log("[INFO] 获取到的签名值为：", signature)
 
headers = {
    "Accept": "*/*",
    "Content-Type": "application/json",
    "x-ca-key": appKey,  
    "x-ca-signature-headers": "x-ca-key,x-ca-nonce,x-ca-timestamp",
    "x-ca-signature": signature,
    "x-ca-timestamp": x_ca_timestamp,
    "x-ca-nonce": x_ca_nonce
}
// headers = {"Accept":"*/*","Content-Type":"application/json","x-ca-key":"27077132","x-ca-signature-headers":"x-ca-key,x-ca-nonce,x-ca-timestamp","x-ca-signature":"EcTuQ676Py2cxj4td5+N4gJ6uZK5bmG76UQHPp23AmY=","x-ca-timestamp":1634291232000,"x-ca-nonce":"0EBA91A2-E2BA-4FD9-AEAA-F3FE46B0776C"}

url_all = base_url + api_get_address_url

 console.log(headers)
const request = require('request')
 results = request({
     url:url_all,
     method:"POST",
     json:true,
     headers:headers
 },function(error,response,body){
     console.error(error)
     console.log(response.statusCode)
     console.log(body)
 })

function uuid(len, radix) {
    var chars = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'.split('');
    var uuid = [], i;
    radix = radix || chars.length;
    if (len) {
      for (i = 0; i < len; i++) {
          uuid[i] = chars[0 | Math.random()*radix];
        }
    } else {
      var r;
      uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
      uuid[14] = '4';
      for (i = 0; i < 36; i++) {
        if (!uuid[i]) {
          r = 0 | Math.random()*16;
          uuid[i] = chars[(i == 19) ? (r & 0x3) | 0x8 : r];
        }
      }
    }
    return uuid.join('');
}
