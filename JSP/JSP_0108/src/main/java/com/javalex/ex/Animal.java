package com.javalex.ex;

	// 클래스 : 객체를 찍어내는 틀
	// Jsp에선 "자바 빈(JavaBean)" 이라고 칭함
public class Animal {
	// 멤버 변수 선언
	/**
	 * 
	 */
	private String kinds; // 종
	private String name;  // 이름
	private int age;      // 나이
	private String number; // 번호
	
	public Animal(String k, String n, int a, String num) {
		this.kinds=k;
		this.number=num;
		this.name=n;
		this.age=a;
	}

	public String getKinds() {
		return kinds;
	}
	public void setKinds(String kinds) {
		this.kinds = kinds;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	
	
	
}
