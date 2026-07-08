아래 함수는 컴파일 에러가 발생한다. 왜 그런지, 어떻게 고쳐야 하는지 적어보자.
```cpp
void PrintName(const FString& Name) {
    Name += TEXT("_Modified");
    UE_LOG(LogTemp, Log, TEXT("%s"), *Name);
}
```

답 : const는 변경될 수 없음을 의미한다. 
