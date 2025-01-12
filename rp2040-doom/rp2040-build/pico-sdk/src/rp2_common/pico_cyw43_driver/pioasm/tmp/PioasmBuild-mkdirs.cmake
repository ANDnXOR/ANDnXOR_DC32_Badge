# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/zapp/dev/dc32_nibbler/pico-sdk/tools/pioasm"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pioasm"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/zapp/dev/dc32_nibbler/rp2040-doom/rp2040-build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
