
#include "g_local.h"

#define Function(f) {#f, f}

mmove_t mmove_reloc;

field_t fields[] = {
	{"classname", FOFS(classname), F_LSTRING},
	{"model", FOFS(model), F_LSTRING},
	{"spawnflags", FOFS(spawnflags), F_INT},
	{"speed", FOFS(speed), F_FLOAT},
	{"accel", FOFS(accel), F_FLOAT},
	{"decel", FOFS(decel), F_FLOAT},
	{"target", FOFS(target), F_LSTRING},
	{"targetname", FOFS(targetname), F_LSTRING},
	{"pathtarget", FOFS(pathtarget), F_LSTRING},
	{"deathtarget", FOFS(deathtarget), F_LSTRING},
	{"killtarget", FOFS(killtarget), F_LSTRING},
	{"combattarget", FOFS(combattarget), F_LSTRING},
	{"message", FOFS(message), F_LSTRING},
	{"team", FOFS(team), F_LSTRING},
	{"wait", FOFS(wait), F_FLOAT},
	{"delay", FOFS(delay), F_FLOAT},
	{"random", FOFS(random), F_FLOAT},
	{"move_origin", FOFS(move_origin), F_VECTOR},
	{"move_angles", FOFS(move_angles), F_VECTOR},
	{"style", FOFS(style), F_INT},
	{"count", FOFS(count), F_INT},
	{"health", FOFS(health), F_INT},
	{"sounds", FOFS(sounds), F_INT},
	{"light", 0, F_IGNORE},
	{"dmg", FOFS(dmg), F_INT},
	{"mass", FOFS(mass), F_INT},
	{"volume", FOFS(volume), F_FLOAT},
	{"attenuation", FOFS(attenuation), F_FLOAT},
	{"map", FOFS(map), F_LSTRING},
	{"origin", FOFS(s.origin), F_VECTOR},
	{"angles", FOFS(s.angles), F_VECTOR},
	{"angle", FOFS(s.angles), F_ANGLEHACK},

	{"goalentity", FOFS(goalentity), F_EDICT, FFL_NOSPAWN},
	{"movetarget", FOFS(movetarget), F_EDICT, FFL_NOSPAWN},
	{"enemy", FOFS(enemy), F_EDICT, FFL_NOSPAWN},
	{"oldenemy", FOFS(oldenemy), F_EDICT, FFL_NOSPAWN},
	{"activator", FOFS(activator), F_EDICT, FFL_NOSPAWN},
	{"groundentity", FOFS(groundentity), F_EDICT, FFL_NOSPAWN},
	{"teamchain", FOFS(teamchain), F_EDICT, FFL_NOSPAWN},
	{"teammaster", FOFS(teammaster), F_EDICT, FFL_NOSPAWN},
	{"owner", FOFS(owner), F_EDICT, FFL_NOSPAWN},
	{"mynoise", FOFS(mynoise), F_EDICT, FFL_NOSPAWN},
	{"mynoise2", FOFS(mynoise2), F_EDICT, FFL_NOSPAWN},
	{"target_ent", FOFS(target_ent), F_EDICT, FFL_NOSPAWN},
	{"chain", FOFS(chain), F_EDICT, FFL_NOSPAWN},

	{"prethink", FOFS(prethink), F_FUNCTION, FFL_NOSPAWN},
	{"think", FOFS(think), F_FUNCTION, FFL_NOSPAWN},
	{"blocked", FOFS(blocked), F_FUNCTION, FFL_NOSPAWN},
	{"touch", FOFS(touch), F_FUNCTION, FFL_NOSPAWN},
	{"use", FOFS(use), F_FUNCTION, FFL_NOSPAWN},
	{"pain", FOFS(pain), F_FUNCTION, FFL_NOSPAWN},
	{"die", FOFS(die), F_FUNCTION, FFL_NOSPAWN},

	{"stand", FOFS(monsterinfo.stand), F_FUNCTION, FFL_NOSPAWN},
	{"idle", FOFS(monsterinfo.idle), F_FUNCTION, FFL_NOSPAWN},
	{"search", FOFS(monsterinfo.search), F_FUNCTION, FFL_NOSPAWN},
	{"walk", FOFS(monsterinfo.walk), F_FUNCTION, FFL_NOSPAWN},
	{"run", FOFS(monsterinfo.run), F_FUNCTION, FFL_NOSPAWN},
	{"dodge", FOFS(monsterinfo.dodge), F_FUNCTION, FFL_NOSPAWN},
	{"attack", FOFS(monsterinfo.attack), F_FUNCTION, FFL_NOSPAWN},
	{"melee", FOFS(monsterinfo.melee), F_FUNCTION, FFL_NOSPAWN},
	{"sight", FOFS(monsterinfo.sight), F_FUNCTION, FFL_NOSPAWN},
	{"checkattack", FOFS(monsterinfo.checkattack), F_FUNCTION, FFL_NOSPAWN},
	{"currentmove", FOFS(monsterinfo.currentmove), F_MMOVE, FFL_NOSPAWN},

	{"endfunc", FOFS(moveinfo.endfunc), F_FUNCTION, FFL_NOSPAWN},

	// temp spawn vars -- only valid when the spawn function is called
	{"lip", STOFS(lip), F_INT, FFL_SPAWNTEMP},
	{"distance", STOFS(distance), F_INT, FFL_SPAWNTEMP},
	{"height", STOFS(height), F_INT, FFL_SPAWNTEMP},
	{"noise", STOFS(noise), F_LSTRING, FFL_SPAWNTEMP},
	{"pausetime", STOFS(pausetime), F_FLOAT, FFL_SPAWNTEMP},
	{"item", STOFS(item), F_LSTRING, FFL_SPAWNTEMP},

//need for item field in edict struct, FFL_SPAWNTEMP item will be skipped on saves
	{"item", FOFS(item), F_ITEM},

	{"gravity", STOFS(gravity), F_LSTRING, FFL_SPAWNTEMP},
	{"sky", STOFS(sky), F_LSTRING, FFL_SPAWNTEMP},
	{"skyrotate", STOFS(skyrotate), F_FLOAT, FFL_SPAWNTEMP},
	{"skyaxis", STOFS(skyaxis), F_VECTOR, FFL_SPAWNTEMP},
	{"minyaw", STOFS(minyaw), F_FLOAT, FFL_SPAWNTEMP},
	{"maxyaw", STOFS(maxyaw), F_FLOAT, FFL_SPAWNTEMP},
	{"minpitch", STOFS(minpitch), F_FLOAT, FFL_SPAWNTEMP},
	{"maxpitch", STOFS(maxpitch), F_FLOAT, FFL_SPAWNTEMP},
	{"nextmap", STOFS(nextmap), F_LSTRING, FFL_SPAWNTEMP},

	{0, 0, 0, 0}

};

field_t		levelfields[] =
{
	{"changemap", LLOFS(changemap), F_LSTRING},

	{"sight_client", LLOFS(sight_client), F_EDICT},
	{"sight_entity", LLOFS(sight_entity), F_EDICT},
	{"sound_entity", LLOFS(sound_entity), F_EDICT},
	{"sound2_entity", LLOFS(sound2_entity), F_EDICT},

	{NULL, 0, F_INT}
};

field_t		clientfields[] =
{
	{"pers.weapon", CLOFS(pers.weapon), F_ITEM},
	{"pers.lastweapon", CLOFS(pers.lastweapon), F_ITEM},
	{"newweapon", CLOFS(newweapon), F_ITEM},

	{NULL, 0, F_INT}
};

/*
============
InitGame

This will be called when the dll is first loaded, which
only happens when a new game is started or a save game
is loaded.
============
*/
void InitGame (void)
{
	gi.dprintf ("==== InitGame ====\nThis is game %s built on %s\n", GAMEVERSION, __DATE__);

	gun_x = gi.cvar ("gun_x", "0", 0);
	gun_y = gi.cvar ("gun_y", "0", 0);
	gun_z = gi.cvar ("gun_z", "0", 0);

	//FIXME: sv_ prefix is wrong for these
	sv_rollspeed = gi.cvar ("sv_rollspeed", "200", 0);
	sv_rollangle = gi.cvar ("sv_rollangle", "2", 0);
	sv_maxvelocity = gi.cvar ("sv_maxvelocity", "2000", 0);
	sv_gravity = gi.cvar ("sv_gravity", "800", 0);

	// noset vars
	dedicated = gi.cvar ("dedicated", "0", CVAR_NOSET);

	// latched vars
	sv_cheats = gi.cvar ("cheats", "0", CVAR_SERVERINFO|CVAR_LATCH);
	gi.cvar ("gamename", GAMEVERSION , CVAR_SERVERINFO | CVAR_LATCH);
	gi.cvar ("gamedate", __DATE__ , CVAR_SERVERINFO | CVAR_LATCH);

	maxclients = gi.cvar ("maxclients", "4", CVAR_SERVERINFO | CVAR_LATCH);
	maxspectators = gi.cvar ("maxspectators", "4", CVAR_SERVERINFO);
	deathmatch = gi.cvar ("deathmatch", "0", CVAR_LATCH);
	coop = gi.cvar ("coop", "0", CVAR_LATCH);
	skill = gi.cvar ("skill", "1", CVAR_LATCH);
	maxentities = gi.cvar ("maxentities", "1024", CVAR_LATCH);

	// change anytime vars
	dmflags = gi.cvar ("dmflags", "0", CVAR_SERVERINFO);
	fraglimit = gi.cvar ("fraglimit", "0", CVAR_SERVERINFO);
	timelimit = gi.cvar ("timelimit", "0", CVAR_SERVERINFO);
	password = gi.cvar ("password", "", CVAR_USERINFO);
	spectator_password = gi.cvar ("spectator_password", "", CVAR_USERINFO);
	needpass = gi.cvar ("needpass", "0", CVAR_SERVERINFO);
	filterban = gi.cvar ("filterban", "1", 0);

	//===================
	//Kirks vars

	gren_dmsg = gi.cvar ("gren_dmsg", "tried to put the pin back", CVAR_SERVERINFO);
	gren_ndmsg = gi.cvar ("gren_ndmg", "found its own grenade", CVAR_SERVERINFO);
	gren_fdmsg = gi.cvar ("gren_fdmg", "found her own grenade", CVAR_SERVERINFO);
	gren_mdmsg = gi.cvar ("gren_mdmg", "found his own grenade", CVAR_SERVERINFO);
	sp_ndmsg = gi.cvar ("splash_ndmg", "blew itself up", CVAR_SERVERINFO);
	sp_fdmsg = gi.cvar ("spalsh_fdmg", "blew herself up", CVAR_SERVERINFO);
	sp_mdmsg = gi.cvar ("splash_mdmg", "blew himself up", CVAR_SERVERINFO);
	bfg_dmsg = gi.cvar ("bfg_dmsg", "should have used a smaller gun", CVAR_SERVERINFO);
	bfg_ndmsg = gi.cvar ("bfg_ndmsg", "killed itslef", CVAR_SERVERINFO);
	bfg_fdmsg = gi.cvar ("bfg_fdmsg", "killed herself", CVAR_SERVERINFO);
	bfg_mdmsg = gi.cvar ("bfg_mdmsg", "killed himself", CVAR_SERVERINFO);
	blast_dmsg = gi.cvar ("blast_dmsg", "was blasted by", CVAR_SERVERINFO);
	shotgun_dmsg = gi.cvar ("shotgun_dmsg", "was killed by", CVAR_SERVERINFO);
	sshot1_dmsg = gi.cvar ("sshotgun_dmsg", "was givin a face lift from", CVAR_SERVERINFO);
	sshot2_dmsg = gi.cvar ("sshotgun2_dmsg", "'s super shotgun", CVAR_SERVERINFO);
	mach_dmsg = gi.cvar ("machinegun_dmsg", "was machinegunned by", CVAR_SERVERINFO);
	chain1_dmsg = gi.cvar ("chaingun1_dmsg", "was assulted by", CVAR_SERVERINFO);
	chain2_dmsg = gi.cvar ("chaingun2_dmsg", "'s chaingun", CVAR_SERVERINFO);
	gren1_dmsg = gi.cvar ("gren1_dmsg", "caught", CVAR_SERVERINFO);
	gren2_dmsg = gi.cvar ("gren2_dmsg", "'s grenade", CVAR_SERVERINFO);
	grens1_dmsg = gi.cvar ("grens1_dmsg", "was shredded by", CVAR_SERVERINFO);
	grens2_dmsg = gi.cvar ("grens2_dmsg", "'s shrapnel", CVAR_SERVERINFO);
	rocket1_dmsg = gi.cvar ("rocket1_dmsg", "got to close to", CVAR_SERVERINFO);
	rocket2_dmsg = gi.cvar ("rocket2_dmsg", "'s rocket", CVAR_SERVERINFO);
	rockets1_dmsg = gi.cvar ("rocketsplash1_dmsg", "tryed to run from", CVAR_SERVERINFO);
	rockets2_dmsg = gi.cvar ("rocketsplash2_dmsg", "'s rocket", CVAR_SERVERINFO);
	hyper1_dmsg = gi.cvar ("hyperblaster1_dmsg", "was hyperblasted by", CVAR_SERVERINFO);
	hyper2_dmsg = gi.cvar ("hyperblaster2_dmsg", "'s hyperblaster", CVAR_SERVERINFO);
	railgun_dmsg = gi.cvar ("railgun_dmsg", "was railed by", CVAR_SERVERINFO);
	bfgl1_dmsg= gi.cvar ("bfglaser1_dmsg", "saw the nice green glow from", CVAR_SERVERINFO);
	bfgl2_dmsg = gi.cvar ("bfglaser2_dmsg", "'s BFG", CVAR_SERVERINFO);
	bfgb1_dmsg = gi.cvar ("bfgblast1_dmsg", "was de-atomized by", CVAR_SERVERINFO);
	bfgb2_dmsg = gi.cvar ("bfgblast2_dmsg", "'s BFG", CVAR_SERVERINFO);
	bfge1_dmsg = gi.cvar ("bfge1_dmsg", "could'nt hide from", CVAR_SERVERINFO);
	bfge2_dmsg = gi.cvar ("bfge2_dmsg", "'s BFG", CVAR_SERVERINFO);
	handgren1_dmsg = gi.cvar ("handgren1_dmsg", "caught", CVAR_SERVERINFO);
	handgren2_dmsg = gi.cvar ("handgren2_dmsg", "'s handgrenade", CVAR_SERVERINFO);
	handgrens1_dmsg = gi.cvar ("handgrenspalsh1_dmsg", "did'nt see", CVAR_SERVERINFO);
	handgrens2_dmsg = gi.cvar ("handgrenspalsh2_dmsg", "'s handgrenade", CVAR_SERVERINFO);
	grenh1_dmsg = gi.cvar ("grenh1_dmsg", "feels", CVAR_SERVERINFO);
	grenh2_dmsg = gi.cvar ("grenh2_dmsg", "'s pain", CVAR_SERVERINFO);
	telef1_dmsg = gi.cvar ("telefrag1_dmsg", "tryed to violate", CVAR_SERVERINFO);
	telef2_dmsg = gi.cvar ("telefrag2_dmsg", "'s personal space", CVAR_SERVERINFO);
	start_health = gi.cvar ("start_health", "100", CVAR_SERVERINFO);
	max_health = gi.cvar ("max_health", "100", CVAR_SERVERINFO);
	max_bullets = gi.cvar ("max_bullets", "200", CVAR_SERVERINFO | CVAR_LATCH);
	max_shells = gi.cvar ("max_shells", "100", CVAR_SERVERINFO | CVAR_LATCH);
	max_rockets = gi.cvar ("max_rockets", "50", CVAR_SERVERINFO | CVAR_LATCH);
	max_grenades = gi.cvar ("max_grenades", "50", CVAR_SERVERINFO | CVAR_LATCH);
	max_cells = gi.cvar ("max_cells", "200", CVAR_SERVERINFO | CVAR_LATCH);
	max_slugs = gi.cvar ("max_slugs", "50", CVAR_SERVERINFO | CVAR_LATCH);
	start_message = gi.cvar ("start_message", "has joined the game", CVAR_SERVERINFO);
	end_message = gi.cvar ("end_message", "has left the game", CVAR_SERVERINFO);
	quad_time = gi.cvar ("quad_time", "300", CVAR_SERVERINFO);
	megahealth_time = gi.cvar ("megahealth_time", "1", CVAR_SERVERINFO);
	megahealth_godown = gi.cvar ("megahealth_godown", "-1", CVAR_SERVERINFO);
	ban_shotgun = gi.cvar ("ban_shotgun", "0", CVAR_SERVERINFO);
	ban_supershotgun = gi.cvar ("ban_supershotgun", "0", CVAR_SERVERINFO);
	ban_machinegun = gi.cvar ("ban_machinegun", "0", CVAR_SERVERINFO);
	ban_chaingun = gi.cvar ("ban_chaingun", "0", CVAR_SERVERINFO);
	ban_grenadelauncher = gi.cvar ("ban_grenadelauncher", "0", CVAR_SERVERINFO);
	ban_grenades = gi.cvar ("ban_grenades", "0", CVAR_SERVERINFO);
	ban_rocketlauncher = gi.cvar ("ban_rocketlauncher", "0", CVAR_SERVERINFO);
	ban_hyperblaster = gi.cvar ("ban_hyperblaster", "0", CVAR_SERVERINFO);
	ban_railgun = gi.cvar ("ban_railgun", "0", CVAR_SERVERINFO);
	ban_bfg = gi.cvar ("ban_bfg", "1", CVAR_SERVERINFO);
	ban_all = gi.cvar ("ban_all", "0", CVAR_SERVERINFO);
	ban_quad = gi.cvar ("ban_quad", "0", CVAR_SERVERINFO | CVAR_LATCH);
	ban_invaul = gi.cvar ("ban_invaul", "1", CVAR_SERVERINFO | CVAR_LATCH);
	use_jetpack = gi.cvar ("use_jetpack", "1", CVAR_SERVERINFO);
	use_hook = gi.cvar ("use_hook", "0", CVAR_SERVERINFO);
	strtblast = gi.cvar ("start_blaster", "0", CVAR_SERVERINFO);
	strtshot = gi.cvar ("start_shotgun", "0", CVAR_SERVERINFO);
	strtsshot = gi.cvar ("start_supershotgun", "0", CVAR_SERVERINFO);
	strtmach = gi.cvar ("start_machinegun", "0", CVAR_SERVERINFO);
	strtchain = gi.cvar ("start_chaingun", "0", CVAR_SERVERINFO);
	strtgren = gi.cvar ("start_grenadelauncher", "0", CVAR_SERVERINFO);
	strtrock = gi.cvar ("start_rocketlauncher", "0", CVAR_SERVERINFO);
	strthyper = gi.cvar ("start_hyperblaster", "0", CVAR_SERVERINFO);
	strtrail = gi.cvar ("start_railgun", "0", CVAR_SERVERINFO);
	strtbfg = gi.cvar ("start_bfg", "0", CVAR_SERVERINFO);
	strtwep = gi.cvar ("start_weapon", "1", CVAR_SERVERINFO);
	strt_shells = gi.cvar ("start_shells", "0", CVAR_SERVERINFO);
	strt_bullets = gi.cvar ("start_bullets", "0", CVAR_SERVERINFO);
	strt_grenades = gi.cvar ("start_grenades", "0", CVAR_SERVERINFO);
	strt_rockets = gi.cvar ("start_rockets", "0", CVAR_SERVERINFO);
	strt_cells = gi.cvar ("start_cells", "0", CVAR_SERVERINFO);
	strt_slugs = gi.cvar ("start_slugs", "0", CVAR_SERVERINFO);
	use_imissionsnd = gi.cvar ("use_intermissionsnd", "1", CVAR_SERVERINFO);
	imission_snd = gi.cvar ("intermission_sound", "world/xian1.wav", CVAR_SERVERINFO);
	hook_dmsg = gi.cvar ("hook_dmsg", "was pooked by", CVAR_SERVERINFO);
	hook2_dmsg = gi.cvar ("hook2_dmsg", "'s hook", CVAR_SERVERINFO);
	ban_health = gi.cvar ("ban_health", "0", CVAR_SERVERINFO);
	ban_health_small = gi.cvar ("ban_health_small", "0", CVAR_SERVERINFO);
	ban_health_large = gi.cvar ("ban_health_large", "0", CVAR_SERVERINFO);
	ban_health_mega = gi.cvar ("ban_health_mega", "0", CVAR_SERVERINFO);
	ban_armor_shard = gi.cvar ("ban_armor_shard", "0", CVAR_SERVERINFO);
	ban_armor_jacket = gi.cvar ("ban_armor_jacket", "0", CVAR_SERVERINFO);
	ban_armor_combat = gi.cvar ("ban_armor_combat", "0", CVAR_SERVERINFO);
	ban_armor_body = gi.cvar ("ban_armor_body", "0", CVAR_SERVERINFO);
   gren_damage = gi.cvar ("grenade_damage", "125", CVAR_SERVERINFO);
   gren_laun_damage = gi.cvar ("grenade_launcher_damage", "120", CVAR_SERVERINFO);
   rr_damage = gi.cvar ("rocket_radius_damage", "120", CVAR_SERVERINFO);
   rdr_damage = gi.cvar ("rocket_damage_radius", "120", CVAR_SERVERINFO);
   r_damage = gi.cvar ("rocket_damage", "100", CVAR_SERVERINFO);
   blaster_damage = gi.cvar ("blaster_damage", "15", CVAR_SERVERINFO);
   hyper_damage = gi.cvar ("hyperblaster_damage", "15", CVAR_SERVERINFO);
   machinegun_damage = gi.cvar ("machinegun_damage", "8", CVAR_SERVERINFO);
   machinegun_kick = gi.cvar ("machinegun_kick", "2", CVAR_SERVERINFO);
   chaingun_damage = gi.cvar ("chaingun_damage", "6", CVAR_SERVERINFO);
   chaingun_kick = gi.cvar ("chaingun_kick", "8", CVAR_SERVERINFO);
   shot_damage = gi.cvar ("shotgun_damage", "4", CVAR_SERVERINFO);
   shot_kick = gi.cvar ("shotgun_kick", "8", CVAR_SERVERINFO);
   sshot_damage = gi.cvar ("supershotgun_damage", "6", CVAR_SERVERINFO);
   sshot_kick = gi.cvar ("supershotgun_kick", "12", CVAR_SERVERINFO);
   railgun_damage = gi.cvar ("railgun_damage", "100", CVAR_SERVERINFO);
   railgun_kick = gi.cvar ("railgun_kick", "200", CVAR_SERVERINFO);
   bfg_damage = gi.cvar ("bfg_damage", "200", CVAR_SERVERINFO);
   strtarmor = gi.cvar ("start_armor", "50", CVAR_SERVERINFO);


	//End Kirks vars
	//====================

	g_select_empty = gi.cvar ("g_select_empty", "0", CVAR_ARCHIVE);

	run_pitch = gi.cvar ("run_pitch", "0.002", 0);
	run_roll = gi.cvar ("run_roll", "0.005", 0);
	bob_up  = gi.cvar ("bob_up", "0.005", 0);
	bob_pitch = gi.cvar ("bob_pitch", "0.002", 0);
	bob_roll = gi.cvar ("bob_roll", "0.002", 0);

	// flood control
	flood_msgs = gi.cvar ("flood_msgs", "4", 0);
	flood_persecond = gi.cvar ("flood_persecond", "4", 0);
	flood_waitdelay = gi.cvar ("flood_waitdelay", "10", 0);

	// dm map list
	sv_maplist = gi.cvar ("sv_maplist", "", 0);

	// items
	InitItems ();

	Com_sprintf (game.helpmessage1, sizeof(game.helpmessage1), "");

	Com_sprintf (game.helpmessage2, sizeof(game.helpmessage2), "");

	// initialize all entities for this game
	game.maxentities = maxentities->value;
	g_edicts =  gi.TagMalloc (game.maxentities * sizeof(g_edicts[0]), TAG_GAME);
	globals.edicts = g_edicts;
	globals.max_edicts = game.maxentities;

	// initialize all clients for this game
	game.maxclients = maxclients->value;
	game.clients = gi.TagMalloc (game.maxclients * sizeof(game.clients[0]), TAG_GAME);
	globals.num_edicts = game.maxclients+1;
}

//=========================================================

void WriteField1 (FILE *f, field_t *field, byte *base)
{
	void		*p;
	int			len;
	int			index;

	if (field->flags & FFL_SPAWNTEMP)
		return;

	p = (void *)(base + field->ofs);
	switch (field->type)
	{
	case F_INT:
	case F_FLOAT:
	case F_ANGLEHACK:
	case F_VECTOR:
	case F_IGNORE:
		break;

	case F_LSTRING:
	case F_GSTRING:
		if ( *(char **)p )
			len = strlen(*(char **)p) + 1;
		else
			len = 0;
		*(int *)p = len;
		break;
	case F_EDICT:
		if ( *(edict_t **)p == NULL)
			index = -1;
		else
			index = *(edict_t **)p - g_edicts;
		*(int *)p = index;
		break;
	case F_CLIENT:
		if ( *(gclient_t **)p == NULL)
			index = -1;
		else
			index = *(gclient_t **)p - game.clients;
		*(int *)p = index;
		break;
	case F_ITEM:
		if ( *(edict_t **)p == NULL)
			index = -1;
		else
			index = *(gitem_t **)p - itemlist;
		*(int *)p = index;
		break;

	//relative to code segment
	case F_FUNCTION:
		if (*(byte **)p == NULL)
			index = 0;
		else
			index = *(byte **)p - ((byte *)InitGame);
		*(int *)p = index;
		break;

	//relative to data segment
	case F_MMOVE:
		if (*(byte **)p == NULL)
			index = 0;
		else
			index = *(byte **)p - (byte *)&mmove_reloc;
		*(int *)p = index;
		break;

	default:
		gi.error ("WriteEdict: unknown field type");
	}
}


void WriteField2 (FILE *f, field_t *field, byte *base)
{
	int			len;
	void		*p;

	if (field->flags & FFL_SPAWNTEMP)
		return;

	p = (void *)(base + field->ofs);
	switch (field->type)
	{
	case F_LSTRING:
		if ( *(char **)p )
		{
			len = strlen(*(char **)p) + 1;
			fwrite (*(char **)p, len, 1, f);
		}
		break;
	}
}

void ReadField (FILE *f, field_t *field, byte *base)
{
	void		*p;
	int			len;
	int			index;

	if (field->flags & FFL_SPAWNTEMP)
		return;

	p = (void *)(base + field->ofs);
	switch (field->type)
	{
	case F_INT:
	case F_FLOAT:
	case F_ANGLEHACK:
	case F_VECTOR:
	case F_IGNORE:
		break;

	case F_LSTRING:
		len = *(int *)p;
		if (!len)
			*(char **)p = NULL;
		else
		{
			*(char **)p = gi.TagMalloc (len, TAG_LEVEL);
			fread (*(char **)p, len, 1, f);
		}
		break;
	case F_EDICT:
		index = *(int *)p;
		if ( index == -1 )
			*(edict_t **)p = NULL;
		else
			*(edict_t **)p = &g_edicts[index];
		break;
	case F_CLIENT:
		index = *(int *)p;
		if ( index == -1 )
			*(gclient_t **)p = NULL;
		else
			*(gclient_t **)p = &game.clients[index];
		break;
	case F_ITEM:
		index = *(int *)p;
		if ( index == -1 )
			*(gitem_t **)p = NULL;
		else
			*(gitem_t **)p = &itemlist[index];
		break;

	//relative to code segment
	case F_FUNCTION:
		index = *(int *)p;
		if ( index == 0 )
			*(byte **)p = NULL;
		else
			*(byte **)p = ((byte *)InitGame) + index;
		break;

	//relative to data segment
	case F_MMOVE:
		index = *(int *)p;
		if (index == 0)
			*(byte **)p = NULL;
		else
			*(byte **)p = (byte *)&mmove_reloc + index;
		break;

	default:
		gi.error ("ReadEdict: unknown field type");
	}
}

//=========================================================

/*
==============
WriteClient

All pointer variables (except function pointers) must be handled specially.
==============
*/
void WriteClient (FILE *f, gclient_t *client)
{
	field_t		*field;
	gclient_t	temp;

	// all of the ints, floats, and vectors stay as they are
	temp = *client;

	// change the pointers to lengths or indexes
	for (field=clientfields ; field->name ; field++)
	{
		WriteField1 (f, field, (byte *)&temp);
	}

	// write the block
	fwrite (&temp, sizeof(temp), 1, f);

	// now write any allocated data following the edict
	for (field=clientfields ; field->name ; field++)
	{
		WriteField2 (f, field, (byte *)client);
	}
}

/*
==============
ReadClient

All pointer variables (except function pointers) must be handled specially.
==============
*/
void ReadClient (FILE *f, gclient_t *client)
{
	field_t		*field;

	fread (client, sizeof(*client), 1, f);

	for (field=clientfields ; field->name ; field++)
	{
		ReadField (f, field, (byte *)client);
	}
}

/*
============
WriteGame

This will be called whenever the game goes to a new level,
and when the user explicitly saves the game.

Game information include cross level data, like multi level
triggers, help computer info, and all client states.

A single player death will automatically restore from the
last save position.
============
*/
void WriteGame (char *filename, qboolean autosave)
{
	FILE	*f;
	int		i;
	char	str[16];

	if (!autosave)
		SaveClientData ();

	f = fopen (filename, "wb");
	if (!f)
		gi.error ("Couldn't open %s", filename);

	memset (str, 0, sizeof(str));
	strcpy (str, __DATE__);
	fwrite (str, sizeof(str), 1, f);

	game.autosaved = autosave;
	fwrite (&game, sizeof(game), 1, f);
	game.autosaved = false;

	for (i=0 ; i<game.maxclients ; i++)
		WriteClient (f, &game.clients[i]);

	fclose (f);
}

void ReadGame (char *filename)
{
	FILE	*f;
	int		i;
	char	str[16];

	gi.FreeTags (TAG_GAME);

	f = fopen (filename, "rb");
	if (!f)
		gi.error ("Couldn't open %s", filename);

	fread (str, sizeof(str), 1, f);
	if (strcmp (str, __DATE__))
	{
		fclose (f);
		gi.error ("Savegame from an older version.\n");
	}

	g_edicts =  gi.TagMalloc (game.maxentities * sizeof(g_edicts[0]), TAG_GAME);
	globals.edicts = g_edicts;

	fread (&game, sizeof(game), 1, f);
	game.clients = gi.TagMalloc (game.maxclients * sizeof(game.clients[0]), TAG_GAME);
	for (i=0 ; i<game.maxclients ; i++)
		ReadClient (f, &game.clients[i]);

	fclose (f);
}

//==========================================================


/*
==============
WriteEdict

All pointer variables (except function pointers) must be handled specially.
==============
*/
void WriteEdict (FILE *f, edict_t *ent)
{
	field_t		*field;
	edict_t		temp;

	// all of the ints, floats, and vectors stay as they are
	temp = *ent;

	// change the pointers to lengths or indexes
	for (field=fields ; field->name ; field++)
	{
		WriteField1 (f, field, (byte *)&temp);
	}

	// write the block
	fwrite (&temp, sizeof(temp), 1, f);

	// now write any allocated data following the edict
	for (field=fields ; field->name ; field++)
	{
		WriteField2 (f, field, (byte *)ent);
	}

}

/*
==============
WriteLevelLocals

All pointer variables (except function pointers) must be handled specially.
==============
*/
void WriteLevelLocals (FILE *f)
{
	field_t		*field;
	level_locals_t		temp;

	// all of the ints, floats, and vectors stay as they are
	temp = level;

	// change the pointers to lengths or indexes
	for (field=levelfields ; field->name ; field++)
	{
		WriteField1 (f, field, (byte *)&temp);
	}

	// write the block
	fwrite (&temp, sizeof(temp), 1, f);

	// now write any allocated data following the edict
	for (field=levelfields ; field->name ; field++)
	{
		WriteField2 (f, field, (byte *)&level);
	}
}


/*
==============
ReadEdict

All pointer variables (except function pointers) must be handled specially.
==============
*/
void ReadEdict (FILE *f, edict_t *ent)
{
	field_t		*field;

	fread (ent, sizeof(*ent), 1, f);

	for (field=fields ; field->name ; field++)
	{
		ReadField (f, field, (byte *)ent);
	}
}

/*
==============
ReadLevelLocals

All pointer variables (except function pointers) must be handled specially.
==============
*/
void ReadLevelLocals (FILE *f)
{
	field_t		*field;

	fread (&level, sizeof(level), 1, f);

	for (field=levelfields ; field->name ; field++)
	{
		ReadField (f, field, (byte *)&level);
	}
}

/*
=================
WriteLevel

=================
*/
void WriteLevel (char *filename)
{
	int		i;
	edict_t	*ent;
	FILE	*f;
	void	*base;

	f = fopen (filename, "wb");
	if (!f)
		gi.error ("Couldn't open %s", filename);

	// write out edict size for checking
	i = sizeof(edict_t);
	fwrite (&i, sizeof(i), 1, f);

	// write out a function pointer for checking
	base = (void *)InitGame;
	fwrite (&base, sizeof(base), 1, f);

	// write out level_locals_t
	WriteLevelLocals (f);

	// write out all the entities
	for (i=0 ; i<globals.num_edicts ; i++)
	{
		ent = &g_edicts[i];
		if (!ent->inuse)
			continue;
		fwrite (&i, sizeof(i), 1, f);
		WriteEdict (f, ent);
	}
	i = -1;
	fwrite (&i, sizeof(i), 1, f);

	fclose (f);
}


/*
=================
ReadLevel

SpawnEntities will allready have been called on the
level the same way it was when the level was saved.

That is necessary to get the baselines
set up identically.

The server will have cleared all of the world links before
calling ReadLevel.

No clients are connected yet.
=================
*/
void ReadLevel (char *filename)
{
	int		entnum;
	FILE	*f;
	int		i;
	void	*base;
	edict_t	*ent;

	f = fopen (filename, "rb");
	if (!f)
		gi.error ("Couldn't open %s", filename);

	// free any dynamic memory allocated by loading the level
	// base state
	gi.FreeTags (TAG_LEVEL);

	// wipe all the entities
	memset (g_edicts, 0, game.maxentities*sizeof(g_edicts[0]));
	globals.num_edicts = maxclients->value+1;

	// check edict size
	fread (&i, sizeof(i), 1, f);
	if (i != sizeof(edict_t))
	{
		fclose (f);
		gi.error ("ReadLevel: mismatched edict size");
	}

	// check function pointer base address
	fread (&base, sizeof(base), 1, f);
#ifdef _WIN32
	if (base != (void *)InitGame)
	{
		fclose (f);
		gi.error ("ReadLevel: function pointers have moved");
	}
#else
	gi.dprintf("Function offsets %d\n", ((byte *)base) - ((byte *)InitGame));
#endif

	// load the level locals
	ReadLevelLocals (f);

	// load all the entities
	while (1)
	{
		if (fread (&entnum, sizeof(entnum), 1, f) != 1)
		{
			fclose (f);
			gi.error ("ReadLevel: failed to read entnum");
		}
		if (entnum == -1)
			break;
		if (entnum >= globals.num_edicts)
			globals.num_edicts = entnum+1;

		ent = &g_edicts[entnum];
		ReadEdict (f, ent);

		// let the server rebuild world links for this ent
		memset (&ent->area, 0, sizeof(ent->area));
		gi.linkentity (ent);
	}

	fclose (f);

	// mark all clients as unconnected
	for (i=0 ; i<maxclients->value ; i++)
	{
		ent = &g_edicts[i+1];
		ent->client = game.clients + i;
		ent->client->pers.connected = false;
	}

	// do any load time things at this point
	for (i=0 ; i<globals.num_edicts ; i++)
	{
		ent = &g_edicts[i];

		if (!ent->inuse)
			continue;

		// fire any cross-level triggers
		if (ent->classname)
			if (strcmp(ent->classname, "target_crosslevel_target") == 0)
				ent->nextthink = level.time + ent->delay;
	}
}
