#include "modding.h"
#include "global.h"
#include "segment_symbols.h"
#include "gLinkHumanSkel.h"
#include "gLinkHumanGreatFairysSwordDL_mesh.h"
#include "gLinkHumanGreatFairysSwordDL_mesh.h"
#include "gLinkHumanRightHandOpenDL_mesh.h"
#include "gLinkHumanLeftHandClosedDL_mesh.h"
#include "gLinkHumanRightHandClosedDL_mesh.h"
#include "gLinkHumanRightHandHoldingOcarinaDL_mesh.h"
#include "gLinkHumanHerosShieldDL_mesh.h"
#include "gLinkHumanLeftHandHoldBottleDL_mesh.h"
#include "object_link_child_DL_018490_mesh.h"
#include "object_link_child_DL_017B40_mesh.h"
#include "gElegyShellHumanDL_mesh.h"
#include "object_mask_bree_DL_0003C0_mesh.h"
#include "gLinkHumanMirrorShieldDL_mesh.h"
#include "object_mask_yofukasi_DL_000490_mesh.h"
#include "object_mask_posthat_DL_000290_mesh.h"
#include "object_mask_json_DL_0004C0_mesh.h"
#include "object_mask_dancer_DL_000EF0_mesh.h"
#include "object_mask_bu_san_DL_000710_mesh.h"
#include "object_mask_skj_DL_0009F0_mesh.h"
#include "object_mask_gibudo_DL_000250_mesh.h"
#include "gDonGeroMaskDL_mesh.h"
#include "gKafeisMaskDL_mesh.h"
#include "object_mask_meoto_DL_0005A0_mesh.h"
#include "object_mask_romerny_DL_0007A0_mesh.h"
#include "object_mir_ray_DL_0004B0_mesh.h"
#include "object_mir_ray_DL_000168_mesh.h"




// Original set of DLs and Textures we're replacing
extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];




RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));

extern Gfx* gPlayerRightHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandInstrumentDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandHookshotDLs[2 * PLAYER_FORM_MAX];

extern Gfx* gPlayerLeftHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandTwoHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandOneHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandBottleDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];

extern Gfx* sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_MAX];

extern Gfx* gLinkHumanGildedSwordHandleDL[];
extern Gfx* gLinkHumanGildedSwordBladeDL[];

extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];

extern Gfx* gKokiriSwordDL[];
extern Gfx* gRazorSwordDL[];
extern Gfx* gLinkHumanBowDL[];
extern Gfx* gLinkHumanHookshotDL[];

extern Gfx* gPlayerHandHoldingShields[];

extern Gfx* D_801C018C[];



// Manual DL replacements for equipment and hands
extern Gfx gLinkHumanRightHandOpenDL[];
extern Gfx gLinkHumanLeftHandClosedDL[];
extern Gfx gLinkHumanRightHandClosedDL[];
extern Gfx gLinkHumanGreatFairysSwordDL[];
extern Gfx gLinkHumanRightHandHoldingOcarinaDL[];
extern Gfx gLinkHumanHerosShieldDL[];
extern Gfx gLinkHumanMirrorShieldDL[];
extern Gfx gLinkHumanLeftHandHoldBottleDL[];
extern Gfx object_link_child_DL_018490[]; // 1st person bow model 
extern Gfx object_link_child_DL_017B40[]; //1st person hookshot model
extern Gfx gElegyShellHumanDL[];
extern Gfx* D_801C0B20[]; // mask array | contents at line 2714 in z_player_lib.c
extern Gfx object_mask_bree_DL_0003C0[];
extern Gfx object_mask_yofukasi_DL_000490[];
extern Gfx object_mask_posthat_DL_000290[];
extern Gfx object_mask_json_DL_0004C0[];
extern Gfx object_mask_dancer_DL_000EF0[];
extern Gfx object_mask_bu_san_DL_000710[];
extern Gfx object_mask_skj_DL_0009F0[];
extern Gfx object_mask_gibudo_DL_000250[];
extern Gfx gDonGeroMaskDL[];
extern Gfx gKafeisMaskDL[];
extern Gfx object_mask_meoto_DL_0005A0[];
extern Gfx object_mask_romerny_DL_0007A0[];
extern Gfx object_mir_ray_DL_0004B0[];
extern Gfx object_mir_ray_DL_000168[];
extern u8 sPlayerFormOcarinaInstruments[];






// Basic Human Link replacement (only skeleton and waist)
RECOMP_HOOK("Player_Init") void on_Player_Init(Actor* thisx, PlayState* play) {
    gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gLinkHumanSkel;

    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanSkel_bone001_gLinkHumanWaistLimb_mesh_layer_Opaque;

    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanSkel_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque;
    
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gLinkHumanSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gLinkHumanSkel_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque;
    sPlayerFormOcarinaInstruments[0] = OCARINA_INSTRUMENT_WHISTLING_FLUTE;
    sPlayerFirstPersonRightShoulderDLs[4] = gLinkHumanSkel_bone016_gLinkHumanRightShoulderLimb_mesh_layer_Opaque;
    sPlayerFirstPersonLeftForearmDLs[4] = gLinkHumanSkel_bone013_gLinkHumanLeftShoulderLimb_mesh_layer_Opaque;
    


    // Mask replacements, found in z_player_lib.c

    // object_mask_truth_DL_0001A0,    // PLAYER_MASK_TRUTH
    D_801C0B20[1] = gKafeisMaskDL_mesh;                  // PLAYER_MASK_KAFEIS_MASK
    D_801C0B20[2] = object_mask_yofukasi_DL_000490_mesh; // PLAYER_MASK_ALL_NIGHT
    // object_mask_rabit_DL_000610,    // PLAYER_MASK_BUNNY
    // object_mask_ki_tan_DL_0004A0,   // PLAYER_MASK_KEATON
    D_801C0B20[5] = object_mask_json_DL_0004C0_mesh;    // PLAYER_MASK_GARO
    D_801C0B20[6] = object_mask_romerny_DL_0007A0_mesh;
    // object_mask_zacho_DL_000700,    // PLAYER_MASK_CIRCUS_LEADER
    D_801C0B20[8] = object_mask_posthat_DL_000290_mesh;  // PLAYER_MASK_POSTMAN
    D_801C0B20[9] = object_mask_meoto_DL_0005A0_mesh;    // PLAYER_MASK_COUPLE
    // object_mask_bigelf_DL_0016F0,   // PLAYER_MASK_GREAT_FAIRY
    D_801C0B20[11] = object_mask_gibudo_DL_000250_mesh;   // PLAYER_MASK_GIBDO
    D_801C0B20[12] = gDonGeroMaskDL_mesh;                 // PLAYER_MASK_DON_GERO
    D_801C0B20[13] = object_mask_dancer_DL_000EF0_mesh;   // PLAYER_MASK_KAMARO
    D_801C0B20[14] = object_mask_skj_DL_0009F0_mesh;      // PLAYER_MASK_CAPTAIN
    // object_mask_stone_DL_000820,    // PLAYER_MASK_STONE
    D_801C0B20[16] = object_mask_bree_DL_0003C0_mesh;     // PLAYER_MASK_BREMEN
    // object_mask_bakuretu_DL_0005C0, // PLAYER_MASK_BLAST
    D_801C0B20[18] = object_mask_bu_san_DL_000710_mesh;   // PLAYER_MASK_SCENTS
    // object_mask_kyojin_DL_000380,   // PLAYER_MASK_GIANT
    // gFierceDeityMaskDL,             // PLAYER_MASK_FIERCE_DEITY
    // gGoronMaskDL,                   // PLAYER_MASK_GORON
    // gZoraMaskDL,                    // PLAYER_MASK_ZORA
    // gDekuMaskDL,                    // PLAYER_MASK_DEKU
    // object_mask_boy_DL_000900,
    // object_mask_goron_DL_0014A0,
    // object_mask_zora_DL_000DB0,
    // object_mask_nuts_DL_001D90,

}





DECLARE_ROM_SEGMENT(object_link_child);
DECLARE_ROM_SEGMENT(object_mir_ray);

void* gRam;
uintptr_t gVrom;
size_t gSize;
RECOMP_HOOK("DmaMgr_ProcessRequest") void on_DmaMgr_RequestSync(DmaRequest* req) {
    gRam = req->dramAddr;
    gVrom = req->vromAddr;
    gSize = req->size;
}

void DL_Swap(Gfx* Orig_DL, Gfx* New_DL) {
        uintptr_t old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        Gfx* to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
}






RECOMP_HOOK_RETURN("DmaMgr_ProcessRequest") void after_dma() {

    if (gVrom == SEGMENT_ROM_START(object_link_child)) {

        DL_Swap(gLinkHumanRightHandOpenDL, gLinkHumanRightHandOpenDL_mesh);
        DL_Swap(gLinkHumanGreatFairysSwordDL, gLinkHumanGreatFairysSwordDL_mesh);
        DL_Swap(gLinkHumanLeftHandClosedDL, gLinkHumanLeftHandClosedDL_mesh);
        DL_Swap(gLinkHumanRightHandClosedDL, gLinkHumanRightHandClosedDL_mesh);
        DL_Swap(gLinkHumanRightHandHoldingOcarinaDL, gLinkHumanRightHandHoldingOcarinaDL_mesh);
        DL_Swap(gLinkHumanHerosShieldDL, gLinkHumanHerosShieldDL_mesh);
        DL_Swap(gLinkHumanMirrorShieldDL, gLinkHumanMirrorShieldDL_mesh);
        DL_Swap(gLinkHumanLeftHandHoldBottleDL, gLinkHumanLeftHandHoldBottleDL_mesh);
        DL_Swap(object_link_child_DL_018490, object_link_child_DL_018490_mesh);
        DL_Swap(object_link_child_DL_017B40, object_link_child_DL_017B40_mesh);
        DL_Swap(gElegyShellHumanDL, gElegyShellHumanDL_mesh);

        gVrom = 0;
        gRam = NULL;

    }

    if (gVrom == SEGMENT_ROM_START(object_mir_ray)) {

        DL_Swap(object_mir_ray_DL_0004B0, object_mir_ray_DL_0004B0_mesh);
        DL_Swap(object_mir_ray_DL_000168, object_mir_ray_DL_000168_mesh);

        gVrom = 0;
        gRam = NULL;

    }

        if (gVrom == SEGMENT_ROM_START(object_mir_ray)) {

        DL_Swap(object_mir_ray_DL_0004B0, object_mir_ray_DL_0004B0_mesh);

        gVrom = 0;
        gRam = NULL;

    }


}






#define MASK_SCALE_MODIFIER 1.0f
#define MASK_DOWNWARDS_OFFSET 250.f
#define BUNNY_DOWNWARDS_OFFSET 400.f
#define MASK_FORWARDS_OFSSEET 200.f
#define MASK_LATERAL_OFFSET 0.f
u8 gPushedMatrix;
extern Gfx* D_801C0B20[];
extern LinkAnimationHeader gPlayerAnim_cl_setmask;
RECOMP_HOOK("Player_PostLimbDrawGameplay") void on_Player_PostLimbDrawGameplay(PlayState* play, s32 limbIndex, Gfx** dList1, Gfx** dList2, Vec3s* rot, Actor* actor) {
    Player* player = (Player*)actor;
    if (limbIndex == PLAYER_LIMB_HEAD) {
        if (((*dList1 != NULL) && ((u32)player->currentMask != PLAYER_MASK_NONE)) &&
            (((player->transformation == PLAYER_FORM_HUMAN) &&
              ((player->skelAnime.animation != &gPlayerAnim_cl_setmask) || (player->skelAnime.curFrame >= 12.0f))) ||
             ((((player->transformation != PLAYER_FORM_HUMAN) && (player->currentMask >= PLAYER_MASK_FIERCE_DEITY)) &&
               ((player->transformation + PLAYER_MASK_FIERCE_DEITY) != player->currentMask)) &&
              (player->skelAnime.curFrame >= 10.0f)))) {   
                s32 maskMinusOne = player->currentMask - 1;
                OPEN_DISPS(play->state.gfxCtx);
                Matrix_Push();
                gPushedMatrix = 1;
                Matrix_Scale(MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MTXMODE_APPLY);
                Matrix_Translate(MASK_FORWARDS_OFSSEET, MASK_DOWNWARDS_OFFSET, MASK_LATERAL_OFFSET, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                CLOSE_DISPS(play->state.gfxCtx);
        } else {
            gPushedMatrix = 0;
        }    
    } else {
        gPushedMatrix = 0;
    }
}

RECOMP_HOOK_RETURN("Player_PostLimbDrawGameplay") void return_Player_PostLimbDrawGameplay(void) {
    if (gPushedMatrix) {
        Matrix_Pop();
    }
    gPushedMatrix = 0;
}





typedef struct BunnyEarKinematics {
    /* 0x0 */ Vec3s rot;
    /* 0x6 */ Vec3s angVel;
} BunnyEarKinematics; // size = 0xC

extern BunnyEarKinematics sBunnyEarKinematics;

RECOMP_PATCH void Player_DrawBunnyHood(PlayState* play) {
    Mtx* mtx = GRAPH_ALLOC(play->state.gfxCtx, 2 * sizeof(Mtx));
    Vec3s earRot;

    OPEN_DISPS(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x0B, mtx);

    Matrix_Push();

    earRot.x = sBunnyEarKinematics.rot.y + 0x3E2;
    earRot.y = sBunnyEarKinematics.rot.z + 0xDBE;
    earRot.z = sBunnyEarKinematics.rot.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f + BUNNY_DOWNWARDS_OFFSET, -1203.0f - BUNNY_DOWNWARDS_OFFSET, -240.0f, &earRot);
    Matrix_Scale(MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MTXMODE_APPLY);

    Matrix_ToMtx(mtx++);

    earRot.x = sBunnyEarKinematics.rot.y - 0x3E2;
    earRot.y = -sBunnyEarKinematics.rot.z - 0xDBE;
    earRot.z = sBunnyEarKinematics.rot.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f + BUNNY_DOWNWARDS_OFFSET, -1203.0f - BUNNY_DOWNWARDS_OFFSET, 240.0f, &earRot);
    Matrix_Scale(MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MASK_SCALE_MODIFIER, MTXMODE_APPLY);

    Matrix_ToMtx(mtx);

    Matrix_Pop();

    CLOSE_DISPS(play->state.gfxCtx);
}









#include "gLinkHumanSkelCustom_okarina_startAnim.h"
#include "gLinkHumanSkelCustom_okarina_swingAnim.h"
#include "gLinkHumanSkelCustom_okarina_walkAnim.h"
#include "gLinkHumanSkelCustom_okarina_walkbAnim.h"



extern LinkAnimationHeader gPlayerAnim_link_normal_okarina_start[];
extern LinkAnimationHeader gPlayerAnim_link_normal_okarina_swing[];
extern LinkAnimationHeader gPlayerAnim_clink_normal_okarina_walk[];
extern LinkAnimationHeader gPlayerAnim_clink_normal_okarina_walkB[];
extern LinkAnimationHeader gPlayerAnim_alink_dance_loop[];

void updateLink(PlayState* play) {
    Player* player = GET_PLAYER(play);
    if (player->transformation == PLAYER_FORM_HUMAN) {
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_normal_okarina_start) = gLinkHumanSkelCustom_okarina_startAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_normal_okarina_swing) = gLinkHumanSkelCustom_okarina_swingAnim;          
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_clink_normal_okarina_walk) = gLinkHumanSkelCustom_okarina_walkAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_clink_normal_okarina_walkB) = gLinkHumanSkelCustom_okarina_walkbAnim;
        

    }
}



RECOMP_CALLBACK("*", recomp_on_play_main)
void mainUpdate(PlayState* play) {
    updateLink(play);
}