difference () {

union() {
    cube([80,20,28], center=true);
    cube([40,20,24], center=true);
    
}

    translate([0,0,3]) cube([23.5,13.30,24], center=true);
    translate([-30,0,0]) cube([21,24,30], center=true);
    translate([30,0,3]) cube([21,24,24], center=true);
    translate([-30,0,-12]) cylinder(r=1.6, h=8, center=true, $fn=80);
    translate([30,0,-12]) cylinder(r=1.6, h=8, center=true, $fn=80);

    translate([14,0,6]) cube([8,6,20], center=true);
    translate([18,0,0]) cube([8,4,8], center=true);

}