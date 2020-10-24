配置支持 HTTPS 访问的 Web 服务器，开启 Web 服务器的 SSL
1. 搭建 CA，并且给自己的Web服务器签发一个证书（截图）
1. 配置开启 SSL 功能的 Web 服务器
1. 通过 HTTPS 访问该 Web 服务器（截图）
1. 通过 WireShark 软件，截取访问过程（截图），建立 SSL/TLS 连接的过程，并且分析其中的步骤

### 1. 搭建 CA，并且给自己的 Web 服务器签发一个证书（截图）

#### 搭建 CA

```bash
# 为 CA 生成一个 RSA 密钥对 ca.key
openssl genrsa -out ca.key 2048

# 生成根证书请求 ca.csr
openssl req -new -in ca.key -out ca.csr

# 为 CA 生成自签名根证书 ca.crt
openssl x509 -req -in ca.csr -signkey ca.key -out ca.crt
```

安装 CA 的根证书 ca.crt 到“受信任的根证书颁发机构”

#### 为服务器签发证书
```bash
# 为服务器生成一个 RSA 密钥对 server.key
openssl genrsa -out server.key 2048

# 生成一个证书请求 server.csr，请求对密钥对 server.key 中的公钥颁发证书
openssl req -new -in server.key -out server.csr

# 签发证书 server.crt，使用 ca.key 为请求 server.csr 签名
openssl x509 -req -days 365 -in server.csr -signkey ca.key -out server.crt
```
