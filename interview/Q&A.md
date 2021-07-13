https://segmentfault.com/a/1190000014044351

# tcp udp http https socket

## 七层网络模型
ISO模型，从上到下

- 应用层

例如http、SMTP、SNMP、FTP、Telnet、SIP、SSH、NFS、RTSP、XMPP、Whois、ENRP

- 表示层

例如 XDR、ASN.1、SMB、AFP、NCP

- 会话层

例如 SSH、RPC、socket

- 传输层

例如 TCP、UDP、RTP、

- 网络层

例如 IP

- 数据链路层

例如 以太网、PPP

- 物理层

线路、无线电等

IP协议对应于网络层，TCP、UDP协议对应于传输层，而HTTP协议对应于应用层，OSI并没有Socket。

## tcp/udp

[![image.png](https://i.postimg.cc/GtBVwMML/image.png)](https://postimg.cc/n9J0q1bg)

**第一次握手：** 建立连接






