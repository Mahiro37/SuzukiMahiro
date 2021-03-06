//================================================================
//
// バリア処理 [barrier.h]
// Author : Suzuki Mahiro
//
//================================================================
#ifndef _BARRIER_H_
#define _BARRIER_H_

//****************************************************************
//インクルードファイル
//****************************************************************
#include "scene2d.h"

//****************************************************************
//マクロ定義
//****************************************************************
#define BARRIER_SIZE	(D3DXVECTOR3(160.0f,160.0f,0.0f))	//バリアのサイズ
#define BARRIER_RADIUS	(80.0f)								//バリアの半径

//****************************************************************
//クラス定義
//****************************************************************
class CBarrier :public CScene2D
{
public:
	//バリアのタイプ
	typedef enum
	{
		BARRIER_TYPE_NONE = 0,
		BARRIER_TYPE_1,			//ライフ１
		BARRIER_TYPE_2,			//ライフ２
		BARRIER_TYPE_3,			//ライフ３
		BARRIER_MAX
	}BARRIER_TYPE;

	CBarrier();
	~CBarrier();
	static CBarrier *Create(D3DXVECTOR3 pos);
	static HRESULT Load(void);
	static void Unload(void);
	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetBarrierLife(int nBarrierLife);

	int GetBarrierLife(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	//テクスチャのポインタ
	static int m_nBarrierLife;				//バリアライフ
};

#endif