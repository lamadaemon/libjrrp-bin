# libjrrp

一个今日人品的 C++ 实现

**由于我是长期火星住民，互联网不发达，不确定现在的政策是什么样子**
**因此暂时不提供源代码，只有编译好的库和头文件**
**如果这项目被认定为 _破解_ 可以联系我删除**

我猜龙猫应该有我qq对吧 (不行也可以发邮件 i@lama.icu)

---

### 你不应该使用该库进行除了获取 UUID、今日人品以外的操作

示例代码:

```c++
#include "jrrp.h"
#include "uuid.h"

#include <cstdio>
#include <cstdlib>

int main() {
    char* uuid;
    char* identify;
    // 获取 Identify
    // Identify 是 PCL 在第一次启动的时候写入注册表的值，计算设备识别码需要用到
    if (PCLGetIdentify(&identify)) {
        // 读取失败
        printf("Error (ERR_READ_IDENTIFY)");
        exit(1);
    }

    // 通过给定 Identify 即可计算出该机器的设备识别码
    // 第二个参数传递 PCLNullptr 即可让库自动获取主板 UUID
    // 如果你用别的途径获取到了，就可以直接传递到第二个参数
    if (PCLGetUniqueID(identify, PCLNullptr, &uuid)) {
        printf("Error (ERR_READ_UUID)");
        exit(2);
    }

    // 计算今日人品
    PCLRenPin jrrp = PCLJrrp(uuid);

    printf("Identify: %s\n", identify);
    printf("UUID: %s\n", uuid);
    printf("Jrrp: %u\n", jrrp);
    printf("%s", PCLStringifyJrrp(jrrp));
}
```

### FAQ

 - Q: 为什么你的 C++ 写的跟 C 一样？
 - A: 因为我讨厌 C++，但是却不得不用，不然某些 Windows API 调用不了

 - Q: 源码呢？
 - A: 就不给你