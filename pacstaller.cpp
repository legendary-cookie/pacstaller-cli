#include "pacstallerconfig.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <pacman.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (geteuid()) {
    std::cout << "Insufficient Permissions!\n";
    return 5;
  }
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << pacstaller_VERSION_MAJOR << "." << pacstaller_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " [pacman package]" << std::endl;
    return 1;
  } else {
    std::string package = argv[1];
    if (access(package.c_str(), F_OK) != -1) {
      std::cout << "Will install package " << package << std::endl;
      char type;
      do {
        std::cout << "Continue? [y/n]" << std::endl;
        std::cin >> type;
      } while (type != 'y' && type != 'n');
      bool install;
      switch (type) {
      case 'y':
        std::cout << "Installing\n";
        install = true;
        break;
      case 'n':
        std::cout << "Canceling...\n";
        install = false;
        break;
      }
      if (install) {
        if (installOffline(package)) {
          std::cout << "\nInstalling was successful!\n";
          return 0;
        } else {
          std::cout << "\nError while installing package!\n";
          return 1;
        }
      } else {
        return 0;
      }
    } else {
      std::cout << "File doesn't exist\n";
      return 1;
    }
  }
}
