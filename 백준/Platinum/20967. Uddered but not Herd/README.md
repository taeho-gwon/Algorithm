# [Platinum III] Uddered but not Herd - 20967 

[문제 링크](https://www.acmicpc.net/problem/20967) 

### 성능 요약

메모리: 92416 KB, 시간: 152 ms

### 분류

비트마스킹(bitmask), 다이나믹 프로그래밍(dp), 비트필드를 이용한 다이나믹 프로그래밍(dp_bitfield)

### 문제 설명

<p>A little known fact about cows is that they have their own version of the alphabet, the "cowphabet". It consists of the 26 letters 'a' through 'z', but when a cow speaks the cowphabet, she lists these letters in a specific ordering that might be different from the order 'abcdefghijklmnopqrstuvwxyz' we are used to hearing.</p>

<p>To pass the time, Bessie's cousin Mildred has been humming the cowphabet over and over again, and Farmer Nhoj is curious how many times she's hummed it.</p>

<p>Given a lowercase string of letters that Farmer Nhoj has heard Mildred say, compute the minimum number of times Mildred must have hummed the entire cowphabet in order for Farmer Nhoj to have heard the given string. Farmer Nhoj isn't always paying attention to what Mildred hums, and so he might have missed some of the letters that Mildred has hummed. The string you are told consists of just the letters that he remembers hearing.</p>

### 입력 

 <p>The only line of input contains the string of lowercase letters that Farmer Nhoj heard Mildred say. This string has length at least <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> and at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^5$</span></mjx-container>.</p>

### 출력 

 <p>Print the minimum number of times Mildred must have hummed the entire cowphabet.</p>

