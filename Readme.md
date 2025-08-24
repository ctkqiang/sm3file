


          
# SM3File 文件加密工具

SM3File 是一个使用中国国密算法 SM3 哈希函数和 SM4 分组密码（CBC 模式）进行文件加密和解密的安全工具。

## 功能特点

- 使用 SM4-CBC 模式进行文件加密
- 使用 SM4-CBC 模式进行文件解密
- 使用 PBKDF2-HMAC-SM3 进行密码派生
- 安全的随机数生成用于加密操作

## 项目结构

```
├── include/
│   ├── crypto.h         # 密码学操作接口
│   ├── file_decryption.h # 文件解密接口
│   └── file_encryption.h # 文件加密接口
├── src/
│   ├── crypto.c         # 密码学操作实现
│   ├── file_decryption.c # 文件解密实现
│   └── file_encryption.c # 文件加密实现
└── sm3file.c            # 主程序入口
```

## 依赖项

- GmSSL（作为子模块包含在 `external/GmSSL/` 中）

## 构建步骤

1. 首先构建 GmSSL：
```bash
cd external/GmSSL
cmake .
make
cd ../..
```

2. 然后构建项目：
```bash
make clean
make
```

编译后的可执行文件将位于 `bin/sm3file`。

## 使用方法

程序支持两种主要操作：

1. 加密文件：
```bash
./bin/sm3file -e 输入文件 输出文件
```

2. 解密文件：
```bash
./bin/sm3file -d 加密文件 输出文件
```

在加密或解密时，程序会提示输入密码。这个密码将通过 PBKDF2-HMAC-SM3 算法派生出加密密钥。

## 安全特性

- 使用 SM4 分组密码的 CBC 模式进行加密/解密
- 使用 PBKDF2-HMAC-SM3 进行基于密码的密钥派生
- 使用安全的随机数生成器进行加密操作
- 使用后安全擦除敏感数据

## 从源码构建

### 环境要求

- C 编译器（GCC 或 Clang）
- CMake（用于构建 GmSSL）
- Make

### 编译步骤

1. 克隆仓库：
```bash
git clone --recursive https://github.com/ctkqiang/sm3file.git
cd sm3file
```

2. 按照上述构建步骤进行编译。


## 贡献

欢迎提交贡献！请随时提交 Pull Request。
        

## 🌟 开源项目赞助计划

### 用捐赠助力发展

感谢您使用本项目！您的支持是开源持续发展的核心动力。  
每一份捐赠都将直接用于：  
✅ 服务器与基础设施维护（魔法城堡的维修费哟~）  
✅ 新功能开发与版本迭代（魔法技能树要升级哒~）  
✅ 文档优化与社区建设（魔法图书馆要扩建呀~）

点滴支持皆能汇聚成海，让我们共同打造更强大的开源工具！  
（小仙子们在向你比心哟~）

---

### 🌐 全球捐赠通道

#### 国内用户

<div align="center" style="margin: 40px 0">

<div align="center">
<table>
<tr>
<td align="center" width="300">
<img src="https://github.com/ctkqiang/ctkqiang/blob/main/assets/IMG_9863.jpg?raw=true" width="200" />
<br />
<strong>🔵 支付宝</strong>（小企鹅在收金币哟~）
</td>
<td align="center" width="300">
<img src="https://github.com/ctkqiang/ctkqiang/blob/main/assets/IMG_9859.JPG?raw=true" width="200" />
<br />
<strong>🟢 微信支付</strong>（小绿龙在收金币哟~）
</td>
</tr>
</table>
</div>
</div>

#### 国际用户

<div align="center" style="margin: 40px 0">
  <a href="https://qr.alipay.com/fkx19369scgxdrkv8mxso92" target="_blank">
    <img src="https://img.shields.io/badge/Alipay-全球支付-00A1E9?style=flat-square&logo=alipay&logoColor=white&labelColor=008CD7">
  </a>
  
  <a href="https://ko-fi.com/F1F5VCZJU" target="_blank">
    <img src="https://img.shields.io/badge/Ko--fi-买杯咖啡-FF5E5B?style=flat-square&logo=ko-fi&logoColor=white">
  </a>
  
  <a href="https://www.paypal.com/paypalme/ctkqiang" target="_blank">
    <img src="https://img.shields.io/badge/PayPal-安全支付-00457C?style=flat-square&logo=paypal&logoColor=white">
  </a>
  
  <a href="https://donate.stripe.com/00gg2nefu6TK1LqeUY" target="_blank">
    <img src="https://img.shields.io/badge/Stripe-企业级支付-626CD9?style=flat-square&logo=stripe&logoColor=white">
  </a>
</div>

---

### 📌 开发者社交图谱

#### 技术交流

<div align="center" style="margin: 20px 0">
  <a href="https://github.com/ctkqiang" target="_blank">
    <img src="https://img.shields.io/badge/GitHub-开源仓库-181717?style=for-the-badge&logo=github">
  </a>
  
  <a href="https://stackoverflow.com/users/10758321/%e9%92%9f%e6%99%ba%e5%bc%ba" target="_blank">
    <img src="https://img.shields.io/badge/Stack_Overflow-技术问答-F58025?style=for-the-badge&logo=stackoverflow">
  </a>
  
  <a href="https://www.linkedin.com/in/ctkqiang/" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-职业网络-0A66C2?style=for-the-badge&logo=linkedin">
  </a>
</div>

#### 社交互动

<div align="center" style="margin: 20px 0">
  <a href="https://www.instagram.com/ctkqiang" target="_blank">
    <img src="https://img.shields.io/badge/Instagram-生活瞬间-E4405F?style=for-the-badge&logo=instagram">
  </a>
  
  <a href="https://twitch.tv/ctkqiang" target="_blank">
    <img src="https://img.shields.io/badge/Twitch-技术直播-9146FF?style=for-the-badge&logo=twitch">
  </a>
  
  <a href="https://github.com/ctkqiang/ctkqiang/blob/main/assets/IMG_9245.JPG?raw=true" target="_blank">
    <img src="https://img.shields.io/badge/微信公众号-钟智强-07C160?style=for-the-badge&logo=wechat">
  </a>
</div>

---

🙌 感谢您成为开源社区的重要一员！  
💬 捐赠后欢迎通过社交平台与我联系，您的名字将出现在项目致谢列表！