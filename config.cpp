class CfgPatches
{
	class LockedCrate
	{
		requiredAddons[] = 
		{
			"DZ_Data",
			"JM_CF_Scripts",
			"NH_Scripts"
		};
	};
};

class CfgMods
{
	class LockedCrate
	{
		type = "mod";
		dependencies[]={"World"}; 
		class defs
		{
            class worldScriptModule
            {
                files[] = {"LockedCrate/scripts/4_World"};
            };
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class BlobLockedCrate: Container_Base
	{
		scope=2;
		displayName = "Shipment Crate";
		descriptionShort="Lockable wooden crate for shipments.";
		model="\DZ\gear\camping\wooden_case.p3d";
		hologramMaterial="wooden_case";
		hologramMaterialPath="dz\gear\camping\data";
		weight=10000;
		itemSize[]={5,11};
		class Cargo
		{
			itemsCargoSize[]={8,10};
		}
		soundImpactType="wood";
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="seachest_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpSeaChest_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="seachest_drop_SoundSet";
					id=898;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=600;
					transferToAttachmentsCoef=0.059999999;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\sea_chest.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\sea_chest.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\sea_chest_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\sea_chest_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\sea_chest_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage=8;
					};
					class Blood
					{
						damage=8;
					};
					class Shock
					{
						damage=8;
					};
				};
			};
		};
	}
}