# parse_json

## 关于此项目

这是一个基于 `c++1x` （暂时没确定版本） 的 `json` 解析器，教程源于：[从零开始的 JSON 库教程](https://zhuanlan.zhihu.com/p/22457315)

## 编译运行

```bash
git clone git@github.com:00nico00/json_parser.git
mkdir build
cd build
cmake .. -GNinja -DCMAKE_TOOLCHAIN_FILE="path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```