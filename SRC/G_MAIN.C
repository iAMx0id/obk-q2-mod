
#include "g_local.h"

game_locals_t	game;
level_locals_t	level;
game_import_t	gi;
game_export_t	globals;
spawn_temp_t	st;

int	sm_meat_index;
int	snd_fry;
int meansOfDeath;

edict_t		*g_edicts;

//=====================
//Kirks cvars

cvar_t  *gren_dmsg;
cvar_t  *gren_ndmsg;
cvar_t  *gren_fdmsg;
cvar_t  *gren_mdmsg;
cvar_t  *sp_ndmsg;
cvar_t  *sp_fdmsg;
cvar_t  *sp_mdmsg;
cvar_t  *bfg_dmsg;
cvar_t  *bfg_ndmsg;
cvar_t  *bfg_fdmsg;
cvar_t  *bfg_mdmsg;
cvar_t  *blast_dmsg;
cvar_t  *shotgun_dmsg;
cvar_t  *sshot1_dmsg;
cvar_t  *sshot2_dmsg;
cvar_t  *mach_dmsg;
cvar_t  *chain1_dmsg;
cvar_t  *chain2_dmsg;
cvar_t  *gren1_dmsg;
cvar_t  *gren2_dmsg;
cvar_t  *grens1_dmsg;
cvar_t  *grens2_dmsg;
cvar_t  *rocket1_dmsg;
cvar_t  *rocket2_dmsg;
cvar_t  *rockets1_dmsg;
cvar_t  *rockets2_dmsg;
cvar_t  *hyper1_dmsg;
cvar_t  *hyper2_dmsg;
cvar_t  *railgun_dmsg;
cvar_t  *bfgl1_dmsg;
cvar_t  *bfgl2_dmsg;
cvar_t  *bfgb1_dmsg;
cvar_t  *bfgb2_dmsg;
cvar_t  *bfge1_dmsg;
cvar_t  *bfge2_dmsg;
cvar_t  *handgren1_dmsg;
cvar_t  *handgren2_dmsg;
cvar_t  *handgrens1_dmsg;
cvar_t  *handgrens2_dmsg;
cvar_t  *grenh1_dmsg;
cvar_t  *grenh2_dmsg;
cvar_t  *telef1_dmsg;
cvar_t  *telef2_dmsg;
cvar_t  *start_health;
cvar_t  *max_health;
cvar_t  *max_bullets;
cvar_t  *max_shells;
cvar_t  *max_rockets;
cvar_t  *max_grenades;
cvar_t  *max_cells;
cvar_t  *max_slugs;
cvar_t  *start_message;
cvar_t  *end_message;
cvar_t  *quad_time;
cvar_t  *megahealth_time;
cvar_t  *megahealth_godown;
cvar_t  *ban_shotgun;
cvar_t  *ban_supershotgun;
cvar_t  *ban_machinegun;
cvar_t  *ban_chaingun;
cvar_t  *ban_grenadelauncher;
cvar_t  *ban_grenades;
cvar_t  *ban_rocketlauncher;
cvar_t  *ban_hyperblaster;
cvar_t  *ban_railgun;
cvar_t  *ban_bfg;
cvar_t  *ban_all;
cvar_t  *ban_quad;
cvar_t  *ban_invaul;
cvar_t  *use_jetpack;
cvar_t  *strtblast;
cvar_t  *strtshot;
cvar_t  *strtsshot;
cvar_t  *strtmach;
cvar_t  *strtchain;
cvar_t  *strtgren;
cvar_t  *strtrock;
cvar_t  *strthyper;
cvar_t  *strtrail;
cvar_t  *strtbfg;
cvar_t  *strtwep;
cvar_t  *strt_shells;
cvar_t  *strt_bullets;
cvar_t  *strt_grenades;
cvar_t  *strt_rockets;
cvar_t  *strt_cells;
cvar_t  *strt_slugs;
cvar_t  *use_imissionsnd;
cvar_t  *imission_snd;
cvar_t  *hook_dmsg;
cvar_t  *hook2_dmsg;
cvar_t  *use_hook;
cvar_t  *ban_health;
cvar_t  *ban_health_small;
cvar_t  *ban_health_large;
cvar_t  *ban_health_mega;
cvar_t  *ban_armor_shard;
cvar_t  *ban_armor_jacket;
cvar_t  *ban_armor_combat;
cvar_t  *ban_armor_body;
//cvar_t  *hook_color;
cvar_t  *gren_damage;
cvar_t  *gren_laun_damage;
cvar_t  *rr_damage;
cvar_t  *rdr_damage;
cvar_t  *r_damage;
cvar_t  *blaster_damage;
cvar_t  *hyper_damage;
cvar_t  *machinegun_damage;
cvar_t  *machinegun_kick;
cvar_t  *chaingun_damage;
cvar_t  *chaingun_kick;
cvar_t  *shot_damage;
cvar_t  *shot_kick;
cvar_t  *sshot_damage;
cvar_t  *sshot_kick;
cvar_t  *railgun_damage;
cvar_t  *railgun_kick;
cvar_t  *bfg_damage;
cvar_t  *strtarmor;

int		hex_color;

cvar_t	*deathmatch;
cvar_t	*coop;
cvar_t	*dmflags;
cvar_t	*skill;
cvar_t	*fraglimit;
cvar_t	*timelimit;
cvar_t	*password;
cvar_t	*spectator_password;
cvar_t	*needpass;
cvar_t	*maxclients;
cvar_t	*maxspectators;
cvar_t	*maxentities;
cvar_t	*g_select_empty;
cvar_t	*dedicated;

cvar_t	*filterban;

cvar_t	*sv_maxvelocity;
cvar_t	*sv_gravity;

cvar_t	*sv_rollspeed;
cvar_t	*sv_rollangle;
cvar_t	*gun_x;
cvar_t	*gun_y;
cvar_t	*gun_z;

cvar_t	*run_pitch;
cvar_t	*run_roll;
cvar_t	*bob_up;
cvar_t	*bob_pitch;
cvar_t	*bob_roll;

cvar_t	*sv_cheats;

cvar_t	*flood_msgs;
cvar_t	*flood_persecond;
cvar_t	*flood_waitdelay;

cvar_t	*sv_maplist;

void SpawnEntities (char *mapname, char *entities, char *spawnpoint);
void ClientThink (edict_t *ent, usercmd_t *cmd);
qboolean ClientConnect (edict_t *ent, char *userinfo);
void ClientUserinfoChanged (edict_t *ent, char *userinfo);
void ClientDisconnect (edict_t *ent);
void ClientBegin (edict_t *ent);
void ClientCommand (edict_t *ent);
void RunEntity (edict_t *ent);
void WriteGame (char *filename, qboolean autosave);
void ReadGame (char *filename);
void WriteLevel (char *filename);
void ReadLevel (char *filename);
void InitGame (void);
void G_RunFrame (void);


//===================================================================


void ShutdownGame (void)
{
	gi.dprintf ("==== ShutdownGame ====\n");

	gi.FreeTags (TAG_LEVEL);
	gi.FreeTags (TAG_GAME);
}


/*
=================
GetGameAPI

Returns a pointer to the structure with all entry points
and global variables
=================
*/
game_export_t *GetGameAPI (game_import_t *import)
{
	gi = *import;

	globals.apiversion = GAME_API_VERSION;
	globals.Init = InitGame;
	globals.Shutdown = ShutdownGame;
	globals.SpawnEntities = SpawnEntities;

	globals.WriteGame = WriteGame;
	globals.ReadGame = ReadGame;
	globals.WriteLevel = WriteLevel;
	globals.ReadLevel = ReadLevel;

	globals.ClientThink = ClientThink;
	globals.ClientConnect = ClientConnect;
	globals.ClientUserinfoChanged = ClientUserinfoChanged;
	globals.ClientDisconnect = ClientDisconnect;
	globals.ClientBegin = ClientBegin;
	globals.ClientCommand = ClientCommand;

	globals.RunFrame = G_RunFrame;

	globals.ServerCommand = ServerCommand;

	globals.edict_size = sizeof(edict_t);

	return &globals;
}

#ifndef GAME_HARD_LINKED
// this is only here so the functions in q_shared.c and q_shwin.c can link
void Sys_Error (char *error, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr, error);
	vsprintf (text, error, argptr);
	va_end (argptr);

	gi.error (ERR_FATAL, "%s", text);
}

void Com_Printf (char *msg, ...)
{
	va_list		argptr;
	char		text[1024];

	va_start (argptr, msg);
	vsprintf (text, msg, argptr);
	va_end (argptr);

	gi.dprintf ("%s", text);
}

#endif

//======================================================================


/*
=================
ClientEndServerFrames
=================
*/
void ClientEndServerFrames (void)
{
	int		i;
	edict_t	*ent;

	// calc the player views now that all pushing
	// and damage has been added
	for (i=0 ; i<maxclients->value ; i++)
	{
		ent = g_edicts + 1 + i;
		if (!ent->inuse || !ent->client)
			continue;
		ClientEndServerFrame (ent);
	}

}

/*
=================
CreateTargetChangeLevel

Returns the created target changelevel
=================
*/
edict_t *CreateTargetChangeLevel(char *map)
{
	edict_t *ent;

	ent = G_Spawn ();
	ent->classname = "target_changelevel";
	Com_sprintf(level.nextmap, sizeof(level.nextmap), "%s", map);
	ent->map = level.nextmap;
	return ent;
}

/*
=================
EndDMLevel

The timelimit or fraglimit has been exceeded
=================
*/
void EndDMLevel (void)
{
	edict_t		*ent;
	char *s, *t, *f;
	static const char *seps = " ,\n\r";

	// stay on same level flag
	if ((int)dmflags->value & DF_SAME_LEVEL)
	{
		BeginIntermission (CreateTargetChangeLevel (level.mapname) );
		return;
	}

	// see if it's in the map list
	if (*sv_maplist->string) {
		s = strdup(sv_maplist->string);
		f = NULL;
		t = strtok(s, seps);
		while (t != NULL) {
			if (Q_stricmp(t, level.mapname) == 0) {
				// it's in the list, go to the next one
				t = strtok(NULL, seps);
				if (t == NULL) { // end of list, go to first one
					if (f == NULL) // there isn't a first one, same level
						BeginIntermission (CreateTargetChangeLevel (level.mapname) );
					else
						BeginIntermission (CreateTargetChangeLevel (f) );
				} else
					BeginIntermission (CreateTargetChangeLevel (t) );
				free(s);
				return;
			}
			if (!f)
				f = t;
			t = strtok(NULL, seps);
		}
		free(s);
	}

	if (level.nextmap[0]) // go to a specific map
		BeginIntermission (CreateTargetChangeLevel (level.nextmap) );
	else {	// search for a changelevel
		ent = G_Find (NULL, FOFS(classname), "target_changelevel");
		if (!ent)
		{	// the map designer didn't include a changelevel,
			// so create a fake ent that goes back to the same level
			BeginIntermission (CreateTargetChangeLevel (level.mapname) );
			return;
		}
		BeginIntermission (ent);
	}
}


/*
=================
CheckNeedPass
=================
*/
void CheckNeedPass (void)
{
	int need;

	// if password or spectator_password has changed, update needpass
	// as needed
	if (password->modified || spectator_password->modified)
	{
		password->modified = spectator_password->modified = false;

		need = 0;

		if (*password->string && Q_stricmp(password->string, "none"))
			need |= 1;
		if (*spectator_password->string && Q_stricmp(spectator_password->string, "none"))
			need |= 2;

		gi.cvar_set("needpass", va("%d", need));
	}
}

/*
=================
CheckDMRules
=================
*/
void CheckDMRules (void)
{
	int			i;
	gclient_t	*cl;

	if (level.intermissiontime)
		return;

	if (!deathmatch->value)
		return;

	if (timelimit->value)
	{
		if (level.time >= timelimit->value*60)
		{
			gi.bprintf (PRINT_HIGH, "Timelimit hit.\n");
			EndDMLevel ();
			return;
		}
	}

	if (fraglimit->value)
	{
		for (i=0 ; i<maxclients->value ; i++)
		{
			cl = game.clients + i;
			if (!g_edicts[i+1].inuse)
				continue;

			if (cl->resp.score >= fraglimit->value)
			{
				gi.bprintf (PRINT_HIGH, "Fraglimit hit.\n");
				EndDMLevel ();
				return;
			}
		}
	}
}


/*
=============
ExitLevel
=============
*/
void ExitLevel (void)
{
	int		i;
	edict_t	*ent;
	char	command [256];

	Com_sprintf (command, sizeof(command), "gamemap \"%s\"\n", level.changemap);
	gi.AddCommandString (command);
	level.changemap = NULL;
	level.exitintermission = 0;
	level.intermissiontime = 0;
	ClientEndServerFrames ();

	// clear some things before going to next level
	for (i=0 ; i<maxclients->value ; i++)
	{
		ent = g_edicts + 1 + i;
		if (!ent->inuse)
			continue;
		if (ent->health > ent->client->pers.max_health)
			ent->health = ent->client->pers.max_health;
	}

}

/*
================
G_RunFrame

Advances the world by 0.1 seconds
================
*/
void G_RunFrame (void)
{
	int		i;
	edict_t	*ent;

	level.framenum++;
	level.time = level.framenum*FRAMETIME;

	// choose a client for monsters to target this frame
	AI_SetSightClient ();

	// exit intermissions

	if (level.exitintermission)
	{
		ExitLevel ();
		return;
	}

	//
	// treat each object in turn
	// even the world gets a chance to think
	//
	ent = &g_edicts[0];
	for (i=0 ; i<globals.num_edicts ; i++, ent++)
	{
		if (!ent->inuse)
			continue;

		level.current_entity = ent;

		VectorCopy (ent->s.origin, ent->s.old_origin);

		// if the ground entity moved, make sure we are still on it
		if ((ent->groundentity) && (ent->groundentity->linkcount != ent->groundentity_linkcount))
		{
			ent->groundentity = NULL;
			if ( !(ent->flags & (FL_SWIM|FL_FLY)) && (ent->svflags & SVF_MONSTER) )
			{
				M_CheckGround (ent);
			}
		}

		if (i > 0 && i <= maxclients->value)
		{
			ClientBeginServerFrame (ent);
			continue;
		}

		G_RunEntity (ent);
	}

	// see if it is time to end a deathmatch
	CheckDMRules ();

	// see if needpass needs updated
	CheckNeedPass ();

	// build the playerstate_t structures for all players
	ClientEndServerFrames ();
}

