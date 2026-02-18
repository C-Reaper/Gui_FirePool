#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/FirePool.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/FirePool.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "F:/home/codeleaded/System/Static/Library/FirePool.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


FirePool wrp;

void Resize(AlxWindow* w){
	FirePool_Resize(&wrp,w->Width,w->Height);
}
void Setup(AlxWindow* w){
	wrp = FirePool_New(w->Width,w->Height,1.0f);
	Resize(w);
}
void Update(AlxWindow* w){
	if(Stroke(ALX_MOUSE_L).DOWN){
		FirePool_Interact(&wrp,w->MouseX,w->MouseY,100.0f);
	}

	FirePool_Fire(&wrp,wrp.h - (1 + 5),5);
	wrp.speedy = 1.0f;
	FirePool_Update(&wrp);

	Clear(BLACK);

	FirePool_Render(&wrp,WINDOW_STD_ARGS,0.0f,0.0f);
}
void Delete(AlxWindow* w){
	FirePool_Free(&wrp);
}

int main(){
    if(CreateX("Fire Pool",1900,1000,1,1,Setup,Update,Delete,Resize))
        Start();
    return 0;
}