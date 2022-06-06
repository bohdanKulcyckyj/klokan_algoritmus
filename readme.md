# Klokan

**Zadání projektu:**

Představme si jednoduchou hru pro jednoho hráče, kterou si můžeme pojmenovat třeba „Klokan“. Základem této hry je posloupnost 𝑃 = 𝑝0𝑝1 … 𝑝𝑛−1, která obsahuje 𝑛 číslic 0 až 9, číslice se mohou opakovat.
Matematicky řečeno 𝑝𝑖 ∈ {0, 1, … , 9} pro 𝑖 = 0, 1, … , 𝑛 − 1.
Po posloupnosti 𝑃 skáče klokan a předpokládejme, že se klokan nachází na pozici 𝑖. Klokan může
provést následující skoky:
* může přeskočit na pozici vlevo, tedy na pozici 𝑖 − 1, pokud tato pozice existuje,
4
* může přeskočit na pozici vpravo, tedy na pozici 𝑖 + 1, pokud tato pozice existuje nebo
* může skočit na libovolnou pozici 𝑗 takovou, že 𝑝𝑖 = 𝑝𝑗 pro 𝑖 ≠ 𝑗, jinak řečeno může skočit na
libovolnou jinou pozici v posloupnosti 𝑃 se stejnou číslicí jako je ta na které právě stojí.
Úkolem hráče je dostat, pomocí výše uvedených tří druhů skoků, klokana ze začátku pole na jeho konec
s použitím minimálního počtu skoků.
Vaším úkolem je implementovat funkci, která pro zadanou posloupnost 𝑃, vyřeší tuto hru.
