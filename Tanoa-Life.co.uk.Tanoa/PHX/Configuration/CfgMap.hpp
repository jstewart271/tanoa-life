#define true 1
#define false 0

class CfgMap {
	class Jobs {
		class HM {
			title = "H.M Treasury";
			object = "fed_bank";
			side = "west";
			online = 10;
			notification = true;
			major = true;
		};

		class Prison {
			title = "H.M.P Tanoa";
			object = "";
			side = "west";
			online = 5;
			notification = true;
			major = true;
		};

		class Evidence {
			title = "APC Evidence Locker";
			object = "evidence_locker";
			side = "west";
			online = 10;
			notification = true;
			major = true;
		};
		
		class PoliceGates {
			title = "Police Gate";
			object = "";
			side = "west";
			online = 3;
			notification = false;
			major = false;
		};
	};

	class JobBuildings {
		class HM_Treasury_Power {
			classname[] = {"Land_Dome_Small_F", "Land_Research_house_V1_F"};
			position[] = {{16014.2,16857,0}, {16020.6,16859,0}};
			doorsToLock[] = {{1,2}, {1}};
			moveObjects[] = {};
			job = "HM";
			breakTime = 300;
		};

		class HM_Treasury_Offices {
			class Options {
				class One {
					classname[] = {"Land_MilOffices_V1_F"};
					position[] = {{16009.7,16900.3,0.372055}};
					doorsToLock[] = {{1,2,3,4,5,6,7,8}};
					moveObjects[] = {{"hm_hack", {16009.5,16882.3,1.22979}}};
				};
				class Two {
					classname[] = {"Land_MilOffices_V1_F"};
					position[] = {{16216.4,17071.3,0.0516109}};
					doorsToLock[] = {{1,2,3,4,5,6,7,8}};
					moveObjects[] = {{"hm_hack", {16202.5,17082.6,1.43792}}};
				};
			};
			job = "HM";
			breakTime = 300;
		};

		class HM_Treasury_Vaults {
			class Options {
				class One {
					classname[] = {"Land_Dome_Big_F", "Land_Research_house_V1_F"};
					position[] = {{16019,16953.4,0}, {16015.1,16958.1,0}};
					doorsToLock[] = {{1,2,3}, {1}};
					moveObjects[] = {{"fed_bank", {16012.8,16958.7,0.728953}}};
				};
				class Two {
					classname[] = {"Land_Dome_Big_F", "Land_Research_HQ_F"};
					position[] = {{16015.1,17043.1,0}, {16023.7,17031.4,0}};
					doorsToLock[] = {{1,2,3}, {1,2}};
					moveObjects[] = {{"fed_bank", {16022.6,17028,0.606426}}};
				};
				class Three {
					classname[] = {"Land_Dome_Big_F", "Land_Research_house_V1_F"};
					position[] = {{16084,17082.7,0}, {16092.7,17092.8,0}};
					doorsToLock[] = {{1,2,3}, {1,2,3}};
					moveObjects[] = {{"fed_bank", {16093.7,17095.2,0.771864}}};
				};
				class Four {
					classname[] = {"Land_Dome_Big_F", "Land_Research_HQ_F"};
					position[] = {{16152.7,17044.1,0}, {16151.5,17043.6,0}};
					doorsToLock[] = {{1,2,3}, {1,2}};
					moveObjects[] = {{"fed_bank", {16148.7,17042.7,0.530085}}};
				};
				class Five {
					classname[] = {"Land_Dome_Big_F", "Land_Research_house_V1_F"};
					position[] = {{16152.6,16961.7,0}, {16146.8,16951.2,0}};
					doorsToLock[] = {{1,2,3}, {1,2,3}};
					moveObjects[] = {{"fed_bank", {16147.3,16947.5,0.71666}}};
				};
				class Six {
					classname[] = {"Land_Dome_Big_F", "Land_Research_HQ_F"};
					position[] = {{16084.9,16915.2,0}, {16076.4,16917.9,0}};
					doorsToLock[] = {{1,2,3}, {1,2}};
					moveObjects[] = {{"fed_bank", {16068.2,16916.5,0.559546}}};
				};
			};
			job = "HM";
			breakTime = 300;
		};

		class HM_Prison {
			classname[] = {"Land_MilOffices_V1_F"};
			position[] = {{12150.122,14067.313,0.624}};
			doorsToLock[] = {{1,2,3}};
			moveObjects[] = {};
			job = "Prison";
			breakTime = 300;
		};

		class Evidence_Locker {
			classname[] = {"Land_i_Barracks_V2_F"};
			position[] = {{12648.9,16414.5,0}};
			doorsToLock[] = {{1,2,3,4,5,6,7,8,9}};
			moveObjects[] = {};
			job = "Evidence";
			breakTime = 300;
		};

		class PoliceGates {
			classname[] = {"Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F","Land_BackAlley_01_l_gate_F"};
			position[] = {{3271.33,12963.5,4.262},{3266.04,12975.9,0.37502},{3264.39,12975.4,0.375675},{3261.18,12975.4,0.384973},{3257.97,12975.3,0.398669},{9761.93,15869.1,0.296288},{9770.67,15855.6,0.328003},{9772.31,15856.1,0.329002},{9775.52,15856.1,0.330002},{9778.74,15856.1,0.331001},{13844.3,18566.1,0.231001},{13841.2,18566.8,0.23},{13838.1,18567.6,0.229},{13836.3,18567.5,0.229},{13834.4,18580.9,4.096}};
			doorsToLock[] = {{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1}};
			moveObjects[] = {};
			job = "PoliceGates";
			breakTime = 300;
		};
	};

	class NHSLifts {
		class Kavala {
			Upposition[] = {3767.121,12976.815,15.498};
			Uprotation = 264.072;
			Downposition[] = {3769.902,12971.439,0.096};
			Downrotation = 291.576;
		};
		class Athira {
			Upposition[] = {14398.215,18978.932,16.219};
			Uprotation = 50.758;
			Downposition[] = {14392.317,18981.055,0.860};
			Downrotation = 81.275;
		};
		class Pyrgos {
			Upposition[] = {16640.8,12326.9,16.2};
			Uprotation = 91.613;
			Downposition[] = {16636.887,12332.162,0.744};
			Downrotation = 117.366;
		};
	};

	class moving_Processor_Test {
			class Options {
				class One {
					moveObjects[] = {{"the_moving_test", {4616.2,3366.43,0}}};
					
				};
				class Two {
					moveObjects[] = {{"the_moving_test", {4349.84,3809.9,0}}};
				};
				class Three {
					moveObjects[] = {{"the_moving_test", {4881.51,4712.83,0}}};
				};
			};
		};
};

class CfgATM {
  Tanoa[] = {
    {11748.2,2665.59,0.440165},
    {11745.5,2665.58,0.408736},
    {11742.9,2666.51,0.373438},
    {11741.8,2669.22,0.415605},
    {11741.8,2671.86,0.384177},
    {11459,2527.1,1.05859},
    {11457.1,2527.49,1.05859},
    {11465.9,2533.39,0},
    {11622.7,2653.88,0.105657},
    {11547.8,2567.9,0.109492},
    {11708.5,2764.64,0.109459},
    {5609.13,12504.5,0},
    {6576.8,13096.7,0.0450649},
    {8942.59,13669.2,0.29541},
    {8504.9,12428.3,0},
    {5172.61,8825.34,0},
    {7375.64,7987.43,0.427734},
    {8329.36,9701.33,0},
    {8951.53,10327.3,0},
    {9967.2,13458.4,0.27755},
    {7987.02,7425.29,0.109064},
    {11632.5,13025,0.297254},
    {10934.9,9872.15,0.530396},
    {10815.3,6488.77,0.277501},
    {11174.6,5156.94,0},
    {5771.44,4209.94,0.281817},
    {2460.21,7441.04,0.334812},
    {3020.64,11324.4,0},
    {2124.82,3348.76,0},
    {5380.58,4083.16,0.52646},
    {1881.72,12121.5,0.316625},
    {11632,2975.03,0.577948},
    {11674.1,2265.42,0.33287},
    {12629.3,7597.48,0.369822},
    {14352.7,8736.34,0.0603628},
    {14248.2,11503.6,0.0235634},
    {5678.91,10184.8,0.23397},
    {5815.08,10850.5,0.343333}
  };
};
