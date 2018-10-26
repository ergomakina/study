package main

import (
	"fmt"
	"net/http"

	// "io/ioutil"
	// "strings"
	"github.com/PuerkitoBio/goquery"
)

func main() {
	resp, err := http.Get("https://nfljapan.com/headlines")
	if err != nil {
		//エラー処理
		fmt.Println("取得失敗")
		return
	}
	defer resp.Body.Close()
	//Load the HTML document
	doc, err := goquery.NewDocumentFromReader(resp.Body)
	if err != nil {
		fmt.Println("error occured:", err)
	}
	doc.Find(".listtxt-inner dt a").Each(func(i int, s *goquery.Selection) {
		fmt.Println("s", s.Text())
	})
}
