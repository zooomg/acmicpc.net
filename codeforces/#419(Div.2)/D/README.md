# D

## 문제 요약
수열이 주어지면 문제에 주어진 규칙을 통해 얻어진 결과를 출력하는 문제  
(+,-,+,-,+,-,... 반복)

## 알고리즘
그냥 규칙으로 푸는건줄 -> 조합이네? -> 이항계수구나 -> n^2은 노답인데 ->  
반복제곱법, 모듈러 역원, 페르마의 소정리, 확장 유클리드, 이항계수, 조합, 곱셈역원을 통한 팩토리얼 역원

## 풀이의 흐름

1. 초기생각

~~~~
N 범위 2 * 10^5
브루트포스 적용시 N*(N-1)/2 -> O(N^2) -> 시간초과
N이 짝수일 경우 합으로만 해결할 수 있는 규칙 발견
홀수는 규칙 적용해서 한줄 줄여서 짝수로 만들고
발견한 규칙으로 짝수 -2씩해주면서 계산
마지막 2개의 수가 남았을 때 N*(N-1)/2가 짝수일 경우 뺄셈 홀수일 경우 덧셈
~~~~

2. 는 시간초과
- 여전히 복잡도는 O(N^2)
- 짝수 규칙으로 좀 더 해봄
- 뭔가 또 발견

3. 2번째 생각
~~~~
마지막 2개의 수가 이항계수의 규칙을 가짐
(n k) = nCk = n!/(n-k)!k!
~~~~

4. 는 틀림
- 시간초과는 해소
- 이젠 펙토리얼 숫자가 10^5!
- long long int 범위를 벗어남

5. 3번째 시도
~~~~
(n k)에도 모듈러 연산을 해줌
그런데 나눗셈은 곱셈 덧셈처럼 해줘서는 안됨
모듈러 역원 + 반복제곱법(O(lgN)) 사용해서 펙토리얼 구하기
~~~~

6. 성공

7. 참고한 블로그
- 확장 유클리드
<http://codepractice.tistory.com/79>

- 모듈러 역원
<http://blog.naver.com/PostView.nhn?blogId=whtrb_study&logNo=220771408232&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView>

- 페르마의 소정리
<https://ko.wikipedia.org/wiki/페르마의_소정리>

- 이항계수 통합본
<http://koosaga.com/entry/이항계수-nCr-mod-p-계산하기>

- 반복 제곱법
<http://blog.naver.com/PostView.nhn?blogId=infoefficien&logNo=220266706924&parentCategoryNo=&categoryNo=54&viewDate=&isShowPopularPosts=false&from=postView>

- 이항계수 백준
<https://www.acmicpc.net/blog/view/29>

- 이항계수 코드 참고
<http://jason9319.tistory.com/169>
