# 📚 数据结构学习与实践项目

 一个系统整理与实现数据结构基础知识的项目，使用 C 语言完成核心代码，根据王道并配套学习笔记与运行示例，适合大学课程学习、程序设计竞赛准备、笔试面试复习等场景。

---

## 🧑‍🎓 关于本项目

本项目为作者在学习《王道数据结构》考研课程过程中所做的代码实现与学习记录，旨在通过动手实现和练习，加深对各类数据结构及其算法的理解，强化实际编程能力。

该项目涵盖：

- 常用线性结构与非线性结构的代码实现
- 常见算法及其复杂度分析
- 注释详细、逻辑清晰、便于扩展与测试

---

## 🧭 更新日志与学习计划

| 日期       | 内容                          | 状态     |
| ---------- | ---------------------------- | -------- |
| 2025-05-01 | 完成顺序表                | ✅ 已完成 |
| 2025-05-20 | 完成链表                   | ✅ 已完成 |
| 2025-06-01 | 完成栈与队列             | ✅ 已完成 |
| 2025-07-01 | 完成串             | ✅ 已完成 |
| 2025-07-04 | 完成树             | ✅ 已完成  |
| 2025-07-14 | 开始图             | ⏳ 进行中 |

---

## 🛠 技术栈 & 工具

| 工具/语言        | 用途                            |
| ---------------- | ------------------------------- |
| `C`              | 主体实现语言                    |
| `GCC`            | 编译器（推荐使用 MinGW 版本）   |
| `VSCode`         | 编辑器（配合 Code Runner 插件） |
| `Markdown`       | 学习笔记与文档撰写              |
| `Git` / `GitHub` | 版本控制与协作                  |

---

## 🗺️ 学习路线图（知识图谱）

```text
线性结构
│
├── 顺序表（数组模拟）
├── 链表（单链表、双链表、循环链表）
├── 栈（顺序栈、链栈）
├── 队列（顺序队列、循环队列、链队列）
│
非线性结构
│
├── 树（二叉树、BST、AVL、线索树等）
├── 图（邻接矩阵、邻接表、DFS、BFS）
│
算法应用
│
├── 查找（顺序查找、二分查找、哈希）
└── 排序（冒泡、选择、插入、归并、快速、堆排序）
```

---

## 📁 目录结构说明

```bash
.
├── 顺序表/
│   ├── bin/                    # 可执行文件存放目录
│   ├── 1-0指针.c               # 指针与数组关系示例
│   ├── 1-1创建顺序表.c         # 顺序表初始化
│   ├── 1-2插入操作.c
│   └── ...
├── 链表/
│   ├── bin/                   
│   ├── 单链表基本操作.c
│   └── ...
├── 栈与队列/
├── 树/
├── 图/
├── 查找与排序/
├── doc/                        # 学习笔记（可选）
└── README.md
```

---

## ▶️ 编译与运行说明（推荐 VSCode 环境）

### ✅ 前置要求

- Windows 系统推荐安装 [MinGW](https://www.mingw-w64.org/)
- 推荐编辑器：VSCode + Code Runner 插件

### ⚙️ VSCode 设置建议（`settings.json`）

```json
"code-runner.executorMap": {
  "c": "cd $dir && if (!(Test-Path bin)) { mkdir bin } ; gcc $fileName -o bin/$fileNameWithoutExt.exe ; if ($?) { ./bin/$fileNameWithoutExt.exe }"
},
"files.encoding": "utf8"
```

---

## 📚 推荐书籍与资源

- 📘 《数据结构（C语言版）》— 严蔚敏 / 吴伟民
- 📘 《算法图解》— Aditya Y. Bhargava（入门推荐）
- 💻 [OI Wiki](https://oi-wiki.org/)
- 💻 [LeetCode 数据结构专题](https://leetcode.cn/)

## 💖 为爱发电

如果你喜欢这个项目，或者它对你有帮助，欢迎通过以下方式支持开发者持续创作：

| 微信赞赏 | 支付宝赞赏 |
| -------- | ---------- |
| <img src="https://github.com/user-attachments/assets/56c55ac6-e43f-480a-b87c-49c3eb61021e" width="300" height="400"> | <img src="https://github.com/user-attachments/assets/87747148-76f9-4cd7-8864-f48501bec597" width="300" height="400"> |



你的每一份支持，都是我继续优化的动力！✨

---
## 🤝 贡献与交流

欢迎学习交流，如果你也在学习数据结构或准备面试，可以：

* Fork 本仓库，自行修改与练习
* 提出 PR，贡献代码或优化笔记
* 提出 Issue，反馈疑问或建议

---

