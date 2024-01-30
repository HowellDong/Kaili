# Kaili

## 构建

### 1. 安装vcpkg

```
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
```

然后配置环境变量`VCPKG_ROOT`为vcpkg安装的目录

### 2. 生成解决方案

```
cmake -B build -S . --preset Debug
```

### 3. 编译

```
cmake --build build
```