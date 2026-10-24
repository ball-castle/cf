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

## 发布后全新克隆验证

实际从 GitHub 全新递归克隆本分支的 `544485685fe5524a0847a97e91ac8d0f3909a03e`。子模块检出 `76ae1760c8106d23bab8face9b64c5802b687651`，mode160000和URL正确；template工作区干净。

- 100个模块的源码、16组测试及全部本地include依赖，与两套归一化SHA证据逐项匹配。
- 32个原正式模块、32份历史源码及第一轮4份成品，均与保留基线一致。
- 新克隆内旧/新打印一致性门禁，以及故意破坏的导出/源码/索引回归测试通过。
- 新克隆中重新编译运行runtime、STL、game/string三组功能测试，无编译诊断，全部通过。
- cf历史215份cpp、151个exe的Git条目不变。Windows Defender日志确认隔离了新克隆内7个历史exe，因此不能将该主机的cf工作区称为干净；template不受影响。没有运行这些exe、恢复隔离文件或改变防护配置。

精确命令、输出、哈希和主机限制见 [DELIVERY_ROUND02_VERIFICATION.json](DELIVERY_ROUND02_VERIFICATION.json)。本记录后续提交仅补发布证据，目标gitlink不变。

GitHub Actions在 [本次运行](https://github.com/ball-castle/template/actions/runs/40115687058) 对统一代码入口执行release与sanitizers；最终作业状态写入上述JSON并同步两个PR。
