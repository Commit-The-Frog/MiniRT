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
- 각 정보의 형식이 맞지 않는 줄
- A, L, C 중 하나라도 없는 경우


### MINIRT 메모리 할당 / 해제 구조

< main >
- init_mlx() : mlx 창, 이미지 생성
- parse() : 파싱
- cal_main() : 연산
- render_mlx() : mlx 창에 이미지 렌더링, hook & loop

< init_mlx >
- info.mlx_win 할당
- info.img 할당

< parse >
- file open
- dim 초기화
- 한 줄씩 파싱
  - gnl 로 char* 할당
  - split 으로 char* -> char** 할당
  - obj, light 의 경우 olist, llist 에 연결리스트 노드 할당
  - free_double_char_list 로 char** 해제
  - ( char* 해제 필요 )

< cal_main >
- 카메라 축 계산
- RAY 발사
  - RAY trace

< render_mlx >
- mlx 창에 이미지 렌더
- mlx key hook
  - 창 닫기 + exit
  - ( img, win 해제 필요 )
- mlx loop