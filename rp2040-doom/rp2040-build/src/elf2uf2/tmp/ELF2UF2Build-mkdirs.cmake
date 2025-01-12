# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/zapp/dev/dc32_nibbler/pico-sdk/tools/elf2uf2"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/elf2uf2"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/tmp"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/src/ELF2UF2Build-stamp"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/src"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/src/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()
