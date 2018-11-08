# c++实现的对文件进行加密解密

使用blowfish算法对文件进行加解密。

使用方式

```
  std::string key = "testKey";
  std::string input("mock.data");
  std::string output_en("mock.data.en");//加密后的文件
  std::string output_dec("mock.data.dec");//解密后的文件
  auto cipher = org::mj::encryption::FileCipher::Create(key);
  cipher->encrypt(input, output_en);
  cipher->decrypt(output_en, output_dec);
```