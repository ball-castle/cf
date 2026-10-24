# CF 与 ICPC 训练记录

## 最新个人比赛手册（ROUND02）

原版 `read()` 直接保留；旧代码优先直接收录，包含树存储与 STL 基础。个人模板仍在同一个 `template/` 子模块中。

- [25页赛前补丁 PDF](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/板子打印版/成都站_赛前小技巧与题型补丁_2026.pdf) · [Word](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/板子打印版/成都站_赛前小技巧与题型补丁_2026.docx)
- [280页完整V2 PDF](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/板子打印版/ACM_ICPC_铜牌稳妥覆盖_算法与模型_V2.pdf) · [Word](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/板子打印版/ACM_ICPC_铜牌稳妥覆盖_算法与模型_V2.docx)
- [题型导航](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/HOW_TO_THINK.md) · [90项STL验收](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/STL_AND_DATA_STRUCTURE_COVERAGE.md) · [逐模块来源](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/SOURCE_PROVENANCE.md)
- [本轮代码/打印验证](https://github.com/ball-castle/template/blob/76ae1760c8106d23bab8face9b64c5802b687651/VALIDATION_REPORT_V2.md) · [两仓库交付记录](DELIVERY_ROUND02.md)

下方保留第一轮入口和训练历史；当前资料优先使用上面的个人版。

本仓库保留训练过程中的源码。**有文件不等于已经 AC**；未完成代码、尝试和历史构建产物都可能存在。

## 模板与打印资料

算法模板的唯一权威仓库为 [ball-castle/template](https://github.com/ball-castle/template)，此处 `template/` 是 Git 子模块，不是复制目录。

- [模板入口与正式算法索引](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/README.md)
- [成都站急用 PDF](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/板子打印版/成都站_铜牌冲刺板子_2026.pdf) · [可编辑 Word](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/板子打印版/成都站_铜牌冲刺板子_2026.docx)
- [长期完整版 PDF](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/板子打印版/ACM_ICPC_铜牌算法板子_完整版.pdf) · [可编辑 Word](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/板子打印版/ACM_ICPC_铜牌算法板子_完整版.docx)
- [32 份旧模板审计](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/TEMPLATE_AUDIT.md) · [测试证据](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/VALIDATION_REPORT.md)
- [成都 2024/2025 官方题目分析](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/CHENGDU_2024_2025_ANALYSIS.md) · [针对性复习计划](https://github.com/ball-castle/template/blob/c0792d4a09e34c636eaff03fce69e9b83d8c10a4/BRONZE_TRAINING_PLAN.md)

以上链接固定到本轮已发布的 template 提交，GitHub 可直接打开；本地文件均位于 `template/`。本次交付与验证记录见 [DELIVERY_20261024.md](DELIVERY_20261024.md)。

## 获取与更新

两份 PR 尚未合并时，用本次交付分支即可获取全部成果：

```sh
git clone --branch codex/icpc-chengdu-submodule-20261024 --recurse-submodules https://github.com/ball-castle/cf.git
```

合并后使用默认分支：

```sh
git clone --recurse-submodules https://github.com/ball-castle/cf.git
# 已有克隆：
git submodule update --init --recursive
```

子模块按本仓库记录的提交检出，处于 detached HEAD 正常。如果要修改模板，应先进入子模块建立分支，再提交到独立模板仓库。

```sh
cd template
git switch -c codex/my-template-change
# 修改、测试后 commit 和 push 到 template 仓库
cd ..
git add template
git commit -m "Update verified template submodule"
```

更新顺序：**先发布并合并 template 的修改，再合并 cf 的 gitlink 更新**。不得提交一个仅存在于本机、远端无法下载的子模块 SHA。不要把子模块当空目录覆盖。

## 训练原则

优先复盘错误、写出证明、独立重做和限时模拟。原 README 的“每日多场”只是旧计划，不能替代能力评估。当前复习清单与 AC/WA/未完成/未知状态的证据区分见模板仓库训练报告。

2026-10-24 基线：215 份已跟踪 `.cpp`、151 个已跟踪 `.exe`。本轮新增 `.gitignore` 阻止新构建产物继续进入版本控制；已有历史产物原样保留。
