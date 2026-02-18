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


const int count = 100;
FirePool fp;

void Resize(AlxWindow* w){
	FirePool_Resize(&fp,w->Width,w->Height);
}
void Setup(AlxWindow* w){
	fp = FirePool_New(w->Width,w->Height,1.0f,0.1f);
	Resize(w);
}
void Update(AlxWindow* w){
	if(Stroke(ALX_MOUSE_L).DOWN){
		FirePool_Interact(&fp,w->MouseX,w->MouseY,100.0f);
	}

	FirePool_Fire(&fp,fp.h - (1 + count),count);
	fp.speedy = 100.0f * w->ElapsedTime;
	
	FirePool_Update(&fp);

	Clear(BLACK);

	FirePool_Render(&fp,WINDOW_STD_ARGS,0.0f,0.0f);
}
void Delete(AlxWindow* w){
	FirePool_Free(&fp);
}

int main(){
    if(CreateX("Fire Pool",1900,1000,1,1,Setup,Update,Delete,Resize))
        Start();
    return 0;
}