# Reference

## 정의
Reference(참조) 변수 : 기존에 선언된 변수를 가리키는 변수.
참조 변수를 선언한다는 것은 변수의 별명을 지어준다고 생각하면 되겠다.

## 알게된 점
1. 참조 변수는 초기화할 때 반드시 참조되는 변수를 지정해야한다.
2. 참조 변수는 주소값을 저장하는게 아니다
```
a = 10; aRef = a;
```
aRef에는 a값이 저장된다.
3. 

## 참고자료
https://woo-dev.tistory.com/43
- 포인터와 참조의 차이에 대해 생각하며.

# Trouble Shoting
## RefTest01.cpp
```
    + CategoryInfo          : ParserError: (:) [], ParentContainsEr 
   rorRecordException
    + FullyQualifiedErrorId : AmpersandNotAllowed
```
프로젝트 디렉토리의 이름이 문제였다.
&는 터미널에서 백그라운드 실행을 의미하는 예약어라고 한다.
프로젝트 디렉토리 : Reference&Const ->Reference_Const로 변경

