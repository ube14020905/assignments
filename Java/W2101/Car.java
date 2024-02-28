public class Car {
	private String color;
	private String manifacturer;
	private String tyreBrand;
	private String EngineType;
	private double bootSpace;
	private boolean hasAC;
	private boolean navigation;
	private double price;
	private boolean MusicSystem;
	private String carType;
	
	public Car(String color,String manifacturer,String tyreBrand,String EngineType,double bootSpace,boolean hasAC,boolean navigation,double price,boolean MusicSystem,String carType) {
		this.color=color;
		this.tyreBrand=tyreBrand;
		this.manifacturer=manifacturer;
		this.EngineType=EngineType;
		this.hasAC=hasAC;
		this.bootSpace=bootSpace;
		this.MusicSystem=MusicSystem;
		this.navigation=navigation;
		this.price=price;
		this.carType=carType;
	}
	public static void main(String[] a) {
		Car thar=new Car("black","Mahindra","MRF","BS6",450000,true,true,1800000,true,"suv");
		System.out.println("Car{" +'\n'+
        "color = " + thar.color + '\n' +
        "brand = " + thar.manifacturer + '\n' +
        "engineType = " + thar.EngineType + '\n' +
        "tyre brand = " + thar.tyreBrand + '\n'+
        "bootSpace = " + thar.bootSpace +'\n'+
        "hasAC = " + thar.hasAC +'\n'+
        "hasMusicSystem = " + thar.MusicSystem +'\n'+
        "hasNavigationSystem = " + thar.navigation +'\n'+
        "price = " + thar.price +'\n'+
        "carType =  " + thar.carType + '\n' +
        '}');
	}

}
