/*
 *  @file: Config_Gangs.hpp
 *  @author: Sig
 *
 *  Description: Config for whitelisted gangs, aswell as gang bases
 *  Vehicle skins for gangs will need to be manually added in Config_Vehicles.hpp
 *  Adding new gang bases will require to change config_spawnpoints aswell
 *
 *  Formats:
 *  Gangs
 *    gangID = ""; //ID (string) of the gang that is getting the whitelist
 *    displayName = ""; //Name of the gang
 *    clothingShop = ""; //Config name of the shop that will be used for the gang uniform
 *    uniformTextures[] = {}; //Textures for the gang uniform, 2d array ({<clothing type>, <path to texture>})
 *
 *  Bases
 *    ownerID = ""; //ID (string) of the gang that owns the base. Id is the one used in the database
 */

// -- Todo change texture uniform to base off of here aswell

class CfgWhitelistedGangs {

  class EvolvE {
    gangID = "13301";
    displayName = "EvolvE";
    clothingShop = "EvolvE";
  };

  class Cawdor {
    gangID = "13308";
    displayName = "Cawdor";
    clothingShop = "Cawdor";
  }
};
