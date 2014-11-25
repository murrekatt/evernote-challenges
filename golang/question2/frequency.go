package main

import (
	"fmt"
	"sort"
)

type termslice []*term

type term struct {
	count int
	term string
}

func (t termslice) Len() int {
	return len(t)
}

func (t termslice) Swap(i, j int) {
	t[i], t[j] = t[j], t[i]
}

func (t termslice) Less(i, j int) bool {
    return t[i].count > t[j].count
}

type frequency struct {
	terms map[string]int
}

func CreateFrequency() *frequency {
	return &frequency{ terms: make(map[string]int) }
}

func (f *frequency) Add(term string) {
	f.terms[term]++
}

func (f *frequency) Top(k int) {
	terms := make(termslice, 0, len(f.terms))
	// get all values with corresponding keys
	for key, value := range f.terms {
		// add key-value pairs into array
		terms = append(terms, &term{ count: value, term: key })
	}
	// sort array elements by value decending order
	sort.Sort(terms)
	// print k elements decending
	for _, value := range terms {
		fmt.Println(value.term, ":", value.count)
		k--
		if k == 0 {
			break
		}
	}
}
