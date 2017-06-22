# A

## 문제 요약
n개의 범위값이 주어질때, q개의 범위 내에 k개의 범위가 겹치는 숫자의 개수를 처리하라.

## 알고리즘
세그먼트 트리, lazy propagation

## 변수 설정

- vector<int> tree : segment tree

## 풀이의 흐름

1. 초기생각

~~~~
많이 봤던 문제지만 항상 풀지 못했던 문제.
작년 말에 어떤 유형의 문제인지는 알았으나 풀지 못하는 문제.
그래서 유형(세그먼트 트리)은 알았기에 찾아서 공부
~~~~

2. 세그먼트 트리
<https://www.acmicpc.net/blog/view/9>
<https://www.acmicpc.net/problem/2042>
- 범위 내의 값들의 합을 노드화 시켜서 트리로 저장
- 루트 노드는 처음부터 끝까지의 범위
- 부모 노드는 자식노드의 범위를 합친 값
- 자식 노드는 부모노드의 절반 범위(left node : 앞쪽 / right node : 뒤쪽)
- h(세그먼트 트리의 높이) : ceil(log2(N))
- init(초기화 함수) : O(lg(N))
~~~
init(v, tree, s, e, idx)
idx(노드의 번호) 값으로 트리를 탐색한다. 루트 노드의 번호를 0으로 했을 경우 왼쪽 노드는 idx*2+1 오른쪽 노드는 idx*2+2, 1로 했을 경우 -1씩.
leaf node일 경우 범위 값이 s==e가 된다. 해당 범위의 값은 정의에 따라 v의 s(or e) 값이 된다.
이외의 노드(= 범위 합 노드)는 왼쪽 노드와 오른쪽 노드의 합이다.
~~~
- update(수정) : O(lg(N))
~~~
update(tree, s, e, idx, target, diff)
target : 수정할 노드의 번호
diff : 이전에 노드에 들어있던 숫자의 값과 새로 들어갈 값의 차이
1. s ~ e 사이에 target이 존재하지 않을 경우 탐색을 더 이상 할 필요 없다.
2. s ~ e 사이에 target이 존재할 경우 해당 범위 값을 diff만큼 더해줘서 업데이트 해주고 계속 탐색해야한다.
3. s == e 일 경우 리프 노드이므로 업데이트만 하고 더이상 탐색하지 않는다.
~~~
- sum(범위 합) : O(lg(N))
~~~
sum(tree, s, e, idx, l, r)
1. l ~ r 값이 s ~ e 바깥에 있을 경우 찾는 범위가 아니므로 0을 리턴한다.
2. l ~ r 값이 s ~ e 안에 있을 경우 찾는 범위이므로 해당 값 tree[idx]를 리턴해준다.
3. l ~ r 값이 s ~ e 와 걸쳐있을 경우 더 탐색해서 포함되지 않는 부분을 버려야한다. 이 부분은 자식을 탐색하는 sum의 합을 리턴해주면 가능하다.
~~~

3. lazy propagation
<https://www.acmicpc.net/blog/view/26>
<http://bowbowbow.tistory.com/4>
<https://www.acmicpc.net/problem/10999>
- lazy 배열을 만들어서 바로 업데이트 하지않고 수정할 값을 저장해뒀다가 탐색하면서 지나갈때 반영해준다.
- 기존에 segment tree를 사용하여 하나의 값을 update하는 것이 아닌 범위 값(R)을 update하면 O(RlgN)
- lazy propagation을 사용하면 범위 업데이트 시간 복잡도가 O(lgN)
- 탐색하면서 지나갈때 값을 갱신해줘야하므로 update 및 find 함수에 lazy값을 확인하는 함수와 lazy값을 갱신해주는 코드를 넣어야 한다.
- lazy값에 해당 노드의 범위내 숫자들의 개수를 곱해주면 굳이 리프노드까지 도달하지 않고 그 자리에서 노드 값 변경이 가능하다.
- tree[idx] += (r-l+1)*lazy[idx]
- update_lazy()
~~~
update_lazy(tree,l,r,idx,lazy)
idx에 해당하는 tree node 값을 수정해주고(+(r-l+1)*lazy[idx]) 자식들에게 lazy값을 전파(propagation)한다.
~~~
- update_range() : O(lg(N))
~~~
update_range(tree,s,e,idx,l,r,diff,lazy)
기존의 segment tree의 find 함수와 비슷하게 동작한다.
1. lazy값을 확인하고 존재하면 업데이트한다.
2. l ~ r 값이 s ~ e 바깥에 존재할 경우 업데이트해 줄 범위가 아니므로 탐색을 종료한다.
3. l ~ r 값이 s ~ e 안에 존재할 경우 (e-s+1)*diff 값을 업데이트 해준 다음 자식들의 lazy 값에 diff 값을 더해준다.
4. l ~ r 값이 s ~ e 와 걸쳐있을 경우 더 탐색해서 포함하지 않는 부분을 걸러내야한다.
여기까지 동작한다면 업데이트 해주는 아래 값만 수정이 된다.
5. 위 값도 수정해주기 위해 재귀적 성질을 이용하여 탐색이 끝난 지점, 걸친 부분을 모두 탐색하고 돌아올 지점에 자식들의 값 합으로 수정해준다.
~~~
- find() : O(lg(N))
~~~
find(tree,s,e,idx,l,r,lazy)
1. lazy값을 확인하고 존재하면 업데이트한다.
2. 이하 segment tree sum과 동일
~~~

4. 이제 문제를 다시 풀어본다
- segment tree init을 할 필요 없이 0으로 모두 채워놓는다.
- 채워놓은 segment tree를 update_range를 통해 diff 값을 1로 넣어서 범위 색칠 구현.
- 질의가 들어올때마 segment tree 범위 탐색하는 함수를 만들어서 리프노드가 k 값보다 크거나 같은 수들의 개수를 세서 리턴.
- 는 O(KalgN) 시간초과 (a : 굳이 리프노드까지 탐색해서 그런듯)

5. 다시 생각
- 2번째 단계까지는 옳았다.
- 미리 segment tree 내부에 있는 리프노드 값을 k값 보다 클 경우 1로 만들고 아니면 0으로 만든다.
- 그렇다면 굳이 리프노드까지 가지 않아도 계산 가능
- 기존의 find()를 통해 범위값 입력을 통해 바로 찾는다.
- 통과 O(KlgN)

6. 다른 방법
- Fenwick trees, event sorting, sqrt-decomposition with binary search, Mo's algorithm
- 해설에 나와있는 개쉬운 방법 한글 풀이 <http://hoon222y.tistory.com/157>
