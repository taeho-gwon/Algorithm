# [Gold I] Goblin Garden Guards - 11273 

[문제 링크](https://www.acmicpc.net/problem/11273) 

### 성능 요약

메모리: 7136 KB, 시간: 188 ms

### 분류

자료 구조(data_structures)

### 문제 설명

<p>In an unprecedented turn of events, goblins recently launched an invasion against the Nedewsian city of Mlohkcots. Goblins—small, green critters—love nothing more than to introduce additional entropy into the calm and ordered lives of ordinary people. They fear little, but one of the few things they fear is water.</p>

<p>The goblin invasion has now reached the royal gardens, where the goblins are busy stealing fruit, going for joyrides on the lawnmower and carving the trees into obscene shapes, and King Lrac Fatsug has decreed that this nonsense stop immediately!</p>

<p>Thankfully, the garden is equipped with an automated sprinkler system. Enabling the sprinklers will soak all goblins within range, forcing them to run home and dry themselves.</p>

<p>Serving in the royal garden guards, you have been asked to calculate how many goblins will remain in the royal garden after the sprinklers have been turned on, so that the royal gardeners can plan their next move.</p>

### 입력 

 <p>The input starts with one integer 1 ≤ g ≤ 100 000, the number of goblins in the royal gardens.</p>

<p>Then, for each goblin follows the position of the goblin as two integers, 0 ≤ x<sub>i</sub> ≤ 10 000 and 0 ≤ y<sub>i</sub> ≤ 10 000. The garden is flat, square and all distances are in meters. Due to quantum interference, several goblins can occupy exactly the same spot in the garden.</p>

<p>Then follows one integer 1 ≤ m ≤ 20 000, the number of sprinklers in the garden.</p>

<p>Finally, for each sprinkler follows the location of the sprinkler as two integers 0 ≤ x<sub>i</sub> ≤ 10 000 and 0 ≤ y<sub>i</sub> ≤ 10 000, and the integer radius 1 ≤ r ≤ 100 of the area it covers, meaning that any goblin at a distance of at most r from the point (x<sub>i</sub> , y<sub>i</sub>) will be soaked by this sprinkler. There can be several sprinklers in the same location.</p>

### 출력 

 <p>Output the number of goblins remaining in the garden after the sprinklers have been turned on.</p>

