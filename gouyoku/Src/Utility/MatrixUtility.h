#pragma once
#include <DxLib.h>

class MatrixUtility
{

public:

	// �I�C���[�p�����]�s��XYZ�����擾
	static MATRIX GetMatrixRotateXYZ(const VECTOR& euler);

	// �e�q�̉�]�s�����������
	static MATRIX Multiplication(const MATRIX& child, const MATRIX& parent);

	// �e�q�̃I�C���[�p����������
	static MATRIX Multiplication(const VECTOR& childEuler, const VECTOR& parentEuler);

};
