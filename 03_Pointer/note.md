# Day 3 학습 노트

---

## 🌇 오후: 메모리 관리 (스택/힙, 스마트 포인터)

### 핵심 개념

**스택 vs 힙**
- 스택: 함수 종료 시 자동 정리, 빠름, 크기 제한 있음
- 힙: 명시적 `delete` 필요, 함수 종료 후에도 살아있어야 하는 객체(게임 중 지속되는 `Enemy` 등)에 사용

**스마트 포인터 등장 배경**
- `new`/`delete` 수동 관리 시 흔한 버그: 메모리 누수, 이중 해제, 소유권 불명확
- C++11부터 "스코프를 벗어나면 자동으로 정리"되는 RAII 기반 포인터 도입

**`unique_ptr`**
- 소유자가 단 하나. 복사 금지, `std::move()`로 소유권 이전만 가능
- 다른 곳에서 동시 참조할 필요 없는 객체에 사용 (예: 플레이어가 장착한 무기 하나)

**`shared_ptr`**
- 여러 곳에서 공동 소유 가능, 내부 참조 카운트로 관리
- 마지막 소유자가 스코프를 벗어날 때만 실제 `delete` 발생
- 여러 객체가 공통으로 참조해야 하는 대상에 사용 (예: 여러 몬스터가 공유하는 타겟 정보)
- 실무 팁: 진짜 "공동 소유"가 필요한 게 아니라 단순히 "누구 것인지 가리키기만" 한다면 `weak_ptr` 고려 (다음 학습 주제)

**UE5와의 연결**
- UE5는 `TUniquePtr`/`TSharedPtr` 자체 버전을 씀
- `UObject`(액터, 컴포넌트 등)는 스마트 포인터 대신 UE의 가비지 컬렉터(GC)가 `UPROPERTY()`로 추적
- 스마트 포인터는 UObject가 아닌 순수 C++ 헬퍼 클래스 관리용

### 코드 예시

```cpp
#include <memory>

// unique_ptr: 단일 소유
void CreateEnemies() {
    std::unique_ptr<Enemy> e1 = std::make_unique<Enemy>();
    std::unique_ptr<Enemy> e2 = std::make_unique<Enemy>();
} // 스코프 종료 시 자동 delete (RAII)

// shared_ptr: 공동 소유 + 참조 카운트
std::shared_ptr<int> a = std::make_shared<int>(10);
std::cout << a.use_count() << std::endl; // 1

std::shared_ptr<int> b = a;
std::cout << a.use_count() << std::endl; // 2

{
    std::shared_ptr<int> c = a;
    std::cout << a.use_count() << std::endl; // 3
} // c 소멸 -> 카운트 자동 감소

std::cout << a.use_count() << std::endl; // 2
```

### 주의사항

- `unique_ptr`은 복사 시도 자체가 컴파일 에러 → 실수 방지 장치로 활용 가능
- `shared_ptr` 남용 시 참조 카운트 관리 비용 + 순환 참조로 인한 누수 위험 (A가 B를 shared_ptr로 참조, B도 A를 shared_ptr로 참조하면 서로 카운트가 안 줄어듦) → 다음에 `weak_ptr`로 해결하는 법 학습 예정
- 스마트 포인터를 썼다고 모든 메모리 문제가 해결되는 건 아님 — "소유 관계가 명확한가"를 먼저 설계하는 게 중요

### 다음 학습 추천

- `weak_ptr` — 순환 참조 문제 해결, "공유는 안 하지만 가리키기만" 하는 경우
- Day 4: 템플릿 & STL (`TArray` vs `std::vector` 비교로 이어짐)

---

## 📝 오늘 작성한 프롬프트 & 피드백

### 메모리 누수 문제(1번) 답변 프롬프트
> "메모리를 동적할당하지만 해제하지 않는다. 메모리에는 해제되지 않은 e1, e2가 누적되며 함수가 호출될때마다 새로운 공간에 현재 e1, e2를 만든다."

**피드백**: 문제 진단은 정확했지만, 문제에서 요구한 "unique_ptr로 고쳐봐"라는 두 번째 지시(코드 작성)가 누락됨. 개념 설명 답변 후에는 항상 문제의 모든 요구사항(설명 + 코드)을 체크리스트처럼 확인하는 습관을 들이면 채점 왕복 횟수를 줄일 수 있음.