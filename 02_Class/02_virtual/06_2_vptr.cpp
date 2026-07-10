//클로드 작성 코드
//prompt : 그럼 컴파일 단계에서 virtual 키워드를 만나면 vtable이란 것을 생성하고 객체마다 자신의 vtable을 가지고 있다는거지? 그리고 부모 포인터에 할당될 때에도 이것을 가지고 있다가 함수를 호출하면 알맞은 vtable을 가진 클래스의 함수를 실행한다는것이고? 그럼 vtable은 어떤 형태로 존재하는거야? 메모리에 존재해? 내가 직접 확인할 수 있는 방법이 있을까?
#include <iostream>

class Enemy {
public:
    virtual void Attack() { std::cout << "generic\n"; }
};

class Dragon : public Enemy {
public:
    void Attack() override { std::cout << "fire\n"; }
};

int main() {
    Enemy* e1 = new Enemy();
    Enemy* e2 = new Dragon();

    // 객체 맨 앞 8바이트 = vptr (대부분의 컴파일러에서 이렇게 배치함)
    void* vptr1 = *reinterpret_cast<void**>(e1);
    void* vptr2 = *reinterpret_cast<void**>(e2);

    std::cout << "Enemy instance's vptr: " << vptr1 << std::endl;
    std::cout << "Dragon instance's vptr: " << vptr2 << std::endl; // 다른 주소!
}