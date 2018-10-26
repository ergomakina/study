// https://play.golang.org/
package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strings"
	// "https://github.com/PuerkitoBio/goquery"
)

func main() {
	resp, err := http.Get("https://nfljapan.com/headlines")
	if err != nil {
		//エラー処理
		fmt.Println("取得失敗")
		return
	}
	defer resp.Body.Close()
	// fmt.Println("resp", resp)

	bodyByte, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		//エラー処理
		fmt.Println("取得失敗")
		return
	}
	pageContent := string(bodyByte)
	// fmt.Println("resp", pageContent)

	myIndex := "<title>"
	// myIndex2 := "</title>"
	locate := strings.Index(pageContent, myIndex)
	// locate2 := strings.LastIndex(pageContent, myIndex2)
	fmt.Println(pageContent[locate+len(myIndex) : locate+35])

	//title := strings.Count(pageContent, "title")
	//fmt.Println("title", title)
}
