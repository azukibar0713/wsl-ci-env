- [x] unittest_atcoder_abc024_a.cpp : 子供は100円/人。大人は200円/人。総数が20人以上の場合は50円/人割引になる。このとき子供の人数と大人の人数がが与えられと時に、入場料を計算する。
    - [x] 合計人数が20未満の場合の入場料を求める。
        - [x] 子供が3人入場した場合は3×100=300円
        - [x] 大人が3人入場した場合は3×200=600円
        - [x] 子供が3人、大人が3人入場した場合は3×100+3×200=900円
    - [x] 合計人数が20以上の場合の入場料を求める。
        - [x] 子供が30人入場した場合は30×100-30×50円
        - [x] 大人が30人入場した場合は30×200-30×50円
        - [x] 子供が30人、大人が30人入場した場合は30×100+30×200-(30+30)×50円 