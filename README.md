# MiniRT

## MINIRT 파싱

< 규칙 >
- 각 요소는 하나 이상의 줄바꿈으로 구분된다.
- 한 줄은 하나 이상의 공백으로 구분되는 정보들을 가진다.
- 공백으로 구분되는 정보들의 개수는 요소마다 다르다.<br>
  - A : 3개<br>
  - C : 3개<br>
  - L : 4개<br>
  - sp : 4개<br>
  - pl : 4개<br>
  - cy : 6개<br>
- 정보들의 타입은 다음과 같다.<br>
  - id : 알파벳, A, C, L, sp, pl, cy 중 하나임<br>
  - ratio : 0 ~ 1 사이의 double 값<br>
  - rgb : (0 ~ 255, 0 ~ 255, 0 ~ 255)<br>
  - coord : (double, double, double)<br>
  - vector : (-1 ~ 1, -1 ~ 1, -1 ~ 1)<br>
  - fov : 0 ~ 180 사이의 int<br>
  - diameter/height : 0 이상인 double<br>
- 요소별 정보들의 순서는 다음과 같다.<br>
  - ambient : id ratio rgb<br>
  - camera : id coord vector fov<br>
  - light : id coord ratio rgb<br>
  - sphere : id coord diameter rgb<br>
  - plane : id coord vector rgb<br>
  - cylinder: id coord vector diameter height rgb<br>

< 엣지 케이스 >
- 공백만 있는 줄
- 줄바꿈만 있는 줄
- 정보의 순서가 맞지 않는 줄
- 각 정보의 형식이 맞지 않는 줄<br>
