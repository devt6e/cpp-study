//다음 함수를 참조 버전으로 만들고 null 체크가 왜 필요없어졌는지 말하라.

void Damage(int* Health, int Amount)
{
    if (Health != nullptr) *Health -= Amount;
}

void DamageCBR(int& Health, int Amount)
{
    Health -= Amount;
}

/*
null 체크가 필요없는 이유
레퍼런스는 생성 당시 참조되는 변수가 반드시 필요하다.
따라서 레퍼런스는 null이 존재할 수 없기 때문에 확인할 필요가 없다.
*/