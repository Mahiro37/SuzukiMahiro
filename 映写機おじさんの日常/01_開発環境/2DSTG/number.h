//=============================================================================
//
// 数字の処理 [number.cpp]
// Author : Suzuki Mahiro
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

//*****************************************************************************
//ヘッダファイルのインクルード
//*****************************************************************************
#include "scene2d.h"

//*****************************************************************************
//マクロ定義
//*****************************************************************************
#define NUMBER_SIZE_X		(40.0f)		//数字のXサイズ
#define NUMBER_SIZE_Y		(50.0f)		//数字のYサイズ

//*****************************************************************************
//クラス定義
//*****************************************************************************
class CNumber
{
public:
	//数字の種類の列挙型
	typedef enum
	{
		TYPE_1 = 0,	//解像度高め
		TYPE_2,		//解像度低め
		TYPE_MAX
	}TYPE;

	CNumber();
	~CNumber();
	static HRESULT Load(void);
	static void Unload(void);
	static CNumber *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nNumber, TYPE type);
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, int nNumber, TYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetNumber(int nNumber);
	void SetSize(D3DXVECTOR3 size);
	void SetPos(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos(void);

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;					//バッファ
	static LPDIRECT3DTEXTURE9 m_pTexture[TYPE_MAX];		//テクスチャ
	static LPDIRECT3DDEVICE9 m_pDevice;					//デバイス
	D3DXVECTOR3 m_pos;									//位置
	D3DXVECTOR3 m_size;									//サイズ
	int m_nNumber;										//表示する数字
	TYPE m_type;										//数字のタイプ
};

#endif