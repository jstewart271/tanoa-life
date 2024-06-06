/*
* @File: fn_isSafeZone.sqf
* @Author: ArrogantBread
* @Desc: Checks if the player is in a certain area
*
* Copyright (C) Nathan "ArrogantBread" Wright  - All Rights Reserved - PhoenixRP
* Unauthorized copying of this file, via any medium is strictly prohibited
* without the express permission of Nathan "ArrogantBread" Wright
*/

[
  "GeorgeTown_Greenzone_Safezone",
  "Lijnhaven_Greenzone_Safezone",
  "Hospital_GeorgeTown",
  "Lijnhaven_Hospital",
  "ambulance_1",
  "airport_greenzone",
  "ambulance_2",
  "meeting_grounds",
  "Lijnhaven_Night_Club"
] findIf {player inArea _x} > -1