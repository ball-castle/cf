# ROUND02 两仓库交付

2026-10-25。沿用原 template / cf PR 分支；没有直接合并main或force push。

- template 已发布提交：`76ae1760c8106d23bab8face9b64c5802b687651`。
- 本仓库 `template` gitlink 仍为 mode160000，指向上述已在GitHub可获取的提交；`.gitmodules` URL不变。
- 新增25页补丁、280页完整V2的DOCX/PDF，原四份成品不变。普通整数采用原read，旧树存储与可靠算法直接复用。
- 100模块统一release/ASan+UBSan各188项检查通过；90项STL六维验收、319项铜牌覆盖矩阵、130张模型卡、来源与接口差异报告均已发布。
- 原215份训练cpp和151个历史exe的Git条目保持不变，未运行历史exe。

本地代码与打印证据：[template/VALIDATION_REPORT_V2.md](template/VALIDATION_REPORT_V2.md)。原PR：[template #1](https://github.com/ball-castle/template/pull/1)、[cf #1](https://github.com/ball-castle/cf/pull/1)。

## 复现

```sh
git clone --branch codex/icpc-chengdu-submodule-20261024 --recurse-submodules https://github.com/ball-castle/cf.git
cd cf/template
python3 scripts/run_round02_tests.py
python3 scripts/run_round02_tests.py --sanitize
python3 scripts/check_round02_print.py
```

先合并template PR，再合并cf PR；若squash/rebase改变最终目标SHA，先更新gitlink并重新克隆核验。

发布后的全新克隆和远端CI结果将在本记录下方补齐；当前不把进行中的检查写成通过。
