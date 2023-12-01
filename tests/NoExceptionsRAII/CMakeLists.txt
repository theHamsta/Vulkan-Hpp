# Copyright(c) 2018, NVIDIA CORPORATION. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
set(EXPECTED_BUILD_TESTS OFF)
FetchContent_Declare(
  tl-expected
  URL https://codeload.github.com/TartanLlama/expected/tar.gz/refs/tags/v1.1.0
  URL_HASH SHA256=1db357f46dd2b24447156aaf970c4c40a793ef12a8a9c2ad9e096d9801368df6 # March 2023
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(tl-expected)
# alternative https://github.com/martinmoene/nonstd-lite

vulkan_hpp__setup_test( NAME NoExceptionsRAII LIBRARIES utils tl::expected CXX_STANDARD 23)

if( UNIX )
	target_link_libraries( NoExceptionsRAII PRIVATE ${CMAKE_DL_LIBS} )
endif ()
