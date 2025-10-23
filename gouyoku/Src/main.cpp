#include <DxLib.h>

#include "Application.h"

// WinMain�֐�
//---------------------------------
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	// �C���X�^���X�̐���
	Application::CreateInstance();
	Application::GetInstance()->Init();

	if (Application::GetInstance()->IsInitFail())
	{
		// ���������s
		return -1;
	}

	// ���s
	Application::GetInstance()->Run();

	// ���
	Application::GetInstance()->Delete();

	if (Application::GetInstance()->IsReleaseFail())
	{
		// ������s
		return -1;
	}

	Application::GetInstance()->DeleteInstance();

	return 0;

}
