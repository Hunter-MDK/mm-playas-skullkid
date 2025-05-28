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
extern Gfx object_mask_bree_DL_0003C0[];
extern Gfx* D_801C0B20[]; // mask array | contents at line 2714 in z_player_lib.c
extern Gfx gLinkHumanMirrorShieldDL[];







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
    D_801C0B20[16] = object_mask_bree_DL_0003C0_mesh;
}





DECLARE_ROM_SEGMENT(object_link_child);

void* gRam;
uintptr_t gVrom;
RECOMP_HOOK("DmaMgr_ProcessRequest") void on_DmaMgr_RequestSync(DmaRequest* req) {
    gRam = req->dramAddr;
    gVrom = req->vromAddr;
}


RECOMP_HOOK_RETURN("DmaMgr_ProcessRequest") void after_dma() {

    if (gVrom == SEGMENT_ROM_START(object_link_child)) {

        Gfx* Orig_DL = gLinkHumanRightHandOpenDL;
        Gfx* New_DL = gLinkHumanRightHandOpenDL_mesh;
//////// Upper: Inits Gfx vars | Lower: Actual code that replaces DLs
        uintptr_t old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        Gfx* to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
        Orig_DL = gLinkHumanGreatFairysSwordDL;
        New_DL = gLinkHumanGreatFairysSwordDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
        Orig_DL = gLinkHumanLeftHandClosedDL;
        New_DL = gLinkHumanLeftHandClosedDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
        Orig_DL = gLinkHumanRightHandClosedDL;
        New_DL = gLinkHumanRightHandClosedDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
        Orig_DL = gLinkHumanRightHandHoldingOcarinaDL;
        New_DL = gLinkHumanRightHandHoldingOcarinaDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = gLinkHumanHerosShieldDL;
        New_DL = gLinkHumanHerosShieldDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = gLinkHumanMirrorShieldDL;
        New_DL = gLinkHumanHerosShieldDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = gLinkHumanLeftHandHoldBottleDL;
        New_DL = gLinkHumanLeftHandHoldBottleDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = object_link_child_DL_018490;        // 1st Person Bow model, right hand specifically object_link_child_DL_017B400
        New_DL = object_link_child_DL_018490_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = object_link_child_DL_017B40;        // 1st Person hookshot model, right hand specifically 
        New_DL = object_link_child_DL_017B40_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = gElegyShellHumanDL;
        New_DL = gElegyShellHumanDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////
       Orig_DL = gLinkHumanMirrorShieldDL;
        New_DL = gLinkHumanMirrorShieldDL_mesh;
        old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);
        to_patch = Lib_SegmentedToVirtual(Orig_DL);
        gSPBranchList(to_patch , New_DL);
        gSegments[0x06] = old_segment_6;
///////////////////////////////////////////////

    gVrom = 0;
    gRam = NULL;

    }
}





#define MASK_SCALE_MODIFIER 1.25f
#define MASK_DOWNWARDS_OFFSET 300.f
#define BUNNY_DOWNWARDS_OFFSET 150.f
#define MASK_FORWARDS_OFSSEET 150.f
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
