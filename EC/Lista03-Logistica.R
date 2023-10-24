attach(lista03)
names(lista03)

modelo <- glm(Aquisição ~ Campanha + Sexo, family = binomial(link = "logit"))
summary(modelo)

