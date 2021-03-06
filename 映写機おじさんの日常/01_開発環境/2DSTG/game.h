//=============================================================================
//
// ゲーム処理 [game.h]
// Author : Suzuki Mahiro
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_

//*****************************************************************************
//ヘッダファイルのインクルード
//*****************************************************************************
#include "mode.h"
#include "item.h"

//*****************************************************************************
//前方宣言
//*****************************************************************************
class CFade;

//*****************************************************************************
//クラス定義
//*****************************************************************************
class CGame :public CMode
{
public:
	//ステージの列挙型
	typedef enum
	{
		GAME_STAGE_1 = 0,	//ステージ１
		GAME_STAGE_2,		//ステージ２
		GAME_STAGE_3,		//ステージ３
		GAME_STAGE_CLEAR	//ステージクリア
	}GAME_STAGE;

	CGame();
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetStageNum(int nStageNum);
	static void UpdateStock(list<CItem::ITEMTYPE> StockItem);

	int GetStageNum(void);

private:
	CFade *m_pFade;			//フェードのポインタ
	bool m_bClear;			//クリア判定
	static int m_nCntStage;	//ステージ番号
	bool m_bStartPush;		//スタートボタンを押したかの判定
};

#endif