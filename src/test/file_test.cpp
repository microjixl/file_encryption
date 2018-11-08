//
// Created by micro on 08/11/2018.
//

#include <file_cipher.hpp>
#include <fstream>

int main() {
  std::ofstream os("mock.data", std::ios::out | std::ios::binary);
  std::string data
      ("Blowfish is a symmetric-key block cipher, designed in 1993 by Bruce Schneier and included in a large number of cipher suites and encryption products. Blowfish provides a good encryption rate in software and no effective cryptanalysis of it has been found to date. However, the Advanced Encryption Standard (AES) now receives more attention, and Schneier recommends Twofish for modern applications.[2]\n"
       "\n"
       "Schneier designed Blowfish as a general-purpose algorithm, intended as an alternative to the aging DES and free of the problems and constraints associated with other algorithms. At the time Blowfish was released, many other designs were proprietary, encumbered by patents or were commercial or government secrets. Schneier has stated that, \"Blowfish is unpatented, and will remain so in all countries. The algorithm is hereby placed in the public domain, and can be freely used by anyone.\"[3]");
  os.write(data.c_str(), data.length());
  os.close();

  std::string key = "testKey";
  std::string input("mock.data");
  std::string output_en("mock.data.en");//加密后的文件
  std::string output_dec("mock.data.dec");//解密后的文件
  auto cipher = org::mj::encryption::FileCipher::Create(key);
  cipher->encrypt(input, output_en);
  cipher->decrypt(output_en, output_dec);
  return 0;
}
