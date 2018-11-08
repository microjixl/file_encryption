//
// Created by micro on 08/11/2018.
//

#include <fstream>
#include <iostream>

#include "file_cipher.hpp"
#include <blowfish/blowfish.h>

namespace org {
namespace mj {
namespace encryption {
class FileCipherImpl : public FileCipher {
public:
  explicit FileCipherImpl(const std::string &key) {
    Blowfish_Init(&ctx, (unsigned char *) key.c_str(), static_cast<int>(key.length()));
  }

  bool encrypt(const std::string &file_path, const std::string &output) override {
    std::ofstream os(output, std::ios::out | std::ios::binary);
    if (os.is_open()) {
      std::ifstream is(file_path, std::ios::in | std::ios::binary);
      if (is.is_open()) {
        int length = 8;
        char buffer[length];
        while (!is.eof()) {
          is.read(buffer, length);
          if (!is.eof()) {
            Blowfish_Encrypt(&ctx,
                             reinterpret_cast<unsigned long *>(buffer),
                             reinterpret_cast<unsigned long *>(buffer + 4));

          } else {
            length = is.gcount();
          }
          os.write(buffer, length);
        }

        is.close();
        os.close();
        return true;
      }
    }

    return false;
  }

  bool decrypt(const std::string &file_path, const std::string &output) override {
    std::ofstream os(output, std::ios::out | std::ios::binary);
    if (os.is_open()) {
      std::ifstream is(file_path, std::ios::in | std::ios::binary);
      if (is.is_open()) {
        int length = 8;
        char buffer[length];
        while (!is.eof()) {
          is.read(buffer, length);
          if (!is.eof()) {
            Blowfish_Decrypt(&ctx,
                             reinterpret_cast<unsigned long *>(buffer),
                             reinterpret_cast<unsigned long *>(buffer + 4));

          } else {
            length = is.gcount();
          }
          os.write(buffer, length);
        }

        is.close();
        os.close();
        return true;
      }
    }

    return false;
  }

private:
  BLOWFISH_CTX ctx{};
};

/* static */std::shared_ptr<FileCipher> FileCipher::Create(const std::string &key) {
  return std::make_shared<FileCipherImpl>(key);
}

}
}
}